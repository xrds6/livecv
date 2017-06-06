#include "qcodedeclaration.h"

namespace lcv{

QCodeDeclaration::QCodeDeclaration(const QStringList &identifierChain, QProjectDocument *document)
    : m_identifierPosition(-1)
    , m_identifierLength(0)
    , m_identifierChain(identifierChain)
    , m_valueOffset(-1)
    , m_valueLength(0)
    , m_document(document)
{
}

QCodeDeclaration::QCodeDeclaration(
        const QStringList &identifierChain,
        const QString &identifierType,
        const QStringList &parentType,
        QProjectDocument *document)
    : m_identifierPosition(-1)
    , m_identifierLength(0)
    , m_identifierChain(identifierChain)
    , m_type(identifierType)
    , m_parentType(parentType)
    , m_valueOffset(-1)
    , m_valueLength(0)
    , m_document(document)
{
}

QCodeDeclaration::QCodeDeclaration(
        const QStringList &identifierChain,
        const QString &identifierType,
        const QStringList &parentType,
        int identifierPosition,
        int identifierLength,
        QProjectDocument *document)
    : m_identifierPosition(identifierPosition)
    , m_identifierLength(identifierLength)
    , m_identifierChain(identifierChain)
    , m_type(identifierType)
    , m_parentType(parentType)
    , m_valueOffset(-1)
    , m_valueLength(0)
    , m_document(document)
{
}

QCodeDeclaration::Ptr QCodeDeclaration::create(const QStringList &identifierChain, QProjectDocument *document){
    return QCodeDeclaration::Ptr(new QCodeDeclaration(identifierChain, document));
}

QCodeDeclaration::Ptr QCodeDeclaration::create(
        const QStringList &identifierChain,
        const QString &type,
        const QStringList &parentType,
        QProjectDocument *document)
{
    return QCodeDeclaration::Ptr(new QCodeDeclaration(identifierChain, type, parentType, document));
}

QCodeDeclaration::Ptr QCodeDeclaration::create(
        const QStringList &identifierChain,
        const QString &type,
        const QStringList &parentType,
        int identifierPosition,
        int identifierLength,
        QProjectDocument *document)
{
    return QCodeDeclaration::Ptr(new QCodeDeclaration(
        identifierChain,
        type,
        parentType,
        identifierPosition,
        identifierLength,
        document
    ));
}

QCodeDeclaration::~QCodeDeclaration(){
}

}// namespace
