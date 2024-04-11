#include<bits/stdc++.h>
using namespace std;
//
#define LH +1
#define EH  0
#define RH -1
typedef int ElemType;
//
typedef struct BSTNode{
    ElemType data,num;
    int bf;//balance flag
    struct BSTNode *lchild,*rchild;
}*BSTree,BSTNode;
// p  p 
void R_Rotate(BSTree* p)
{
    // 5  A  p 
    BSTree lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    *p = lc;
}
//// p  p 
void L_Rotate(BSTree* p)
{
    // 6  A  p 
    BSTree rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}
// T  T 
void LeftBalance(BSTree* T)
{
    BSTree lc,rd;
    lc = (*T)->lchild;
    // T  bf  1  bf  -1
    switch (lc->bf)
    {
        case LH:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            rd = lc->rchild;
            switch(rd->bf)
        {
            case LH:
                (*T)->bf = RH;
                lc->bf = EH;
                break;
            case EH:
                (*T)->bf = lc->bf = EH;
                break;
            case RH:
                (*T)->bf = EH;
                lc->bf = LH;
                break;
        }
        rd->bf = EH;
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
        break;
    }
}
//
void RightBalance(BSTree* T)
{
    BSTree lc,rd;
    lc= (*T)->rchild;
    switch (lc->bf)
    {
        case RH:
            (*T)->bf = lc->bf = EH;
            L_Rotate(T);
            break;
        case LH:
            rd = lc->lchild;
            switch(rd->bf)
        {
            case LH:
                (*T)->bf = EH;
                lc->bf = RH;
                break;
            case EH:
                (*T)->bf = lc->bf = EH;
                break;
            case RH:
                (*T)->bf = EH;
                lc->bf = LH;
                break;
        }
        rd->bf = EH;
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
        break;
    }
}
int InsertAVL(BSTree* T,ElemType e,bool* taller,int k)
{
    // e 
    if ((*T)==NULL)
    {
        (*T)=(BSTree)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->num = k;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller=true;
    }
    // e  T  T 
    else if (e < (*T)->data)
    {
        //
        if(!InsertAVL(&(*T)->lchild,e,taller,k))
            return 0;
        // +1
        if(*taller)
        {
            // T  T  1 
            switch ((*T)->bf)
            {
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                case  EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
    }
    // e>T->data  T 
    else
    {
        if(!InsertAVL(&(*T)->rchild,e,taller,k))
            return 0;
        if (*taller)
        {
            switch ((*T)->bf)
            {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                case  RH:
                    RightBalance(T);
                    *taller = false;
                    break;
            }
        }
    }
    return 1;
}
// e 
bool FindNode(BSTree root,ElemType e,BSTree* pos)
{
    BSTree pt = root;
    (*pos) = NULL;
    while(pt)
    {
        if (pt->data == e)
        {
            //postrue
            (*pos) = pt;
            return true;
        }
        else if (pt->data>e)
        {
            pt = pt->lchild;
        }
        else
            pt = pt->rchild;
    }
    return false;
}
//
void InorderTra(BSTree root)
{
    if(root->lchild)
        InorderTra(root->lchild);
   
    printf("%d ",root->data);
   
    if(root->rchild)
        InorderTra(root->rchild);
}

int a[200010][3];
int main()
{
	int n,i,j,l,s,k,m,e,q,t,b,c,z,r;
	cin>>q;
	s=0;
	for(i=1;i<=q;i++)
	{
		cin>>n>>l>>r;
		b=l;
		c=r;
		t=0;
		for(j=1;j<=s;j++)
		{
			a[j][1]=0;
			a[j][2]=0;
		}
		s=0;
		for(j=1;j<=l;j++)
		{
			cin>>e;
			if(e>s) s=e;
			a[e][1]+=1;
		}
		for(j=l+1;j<=n;j++)
		{
			cin>>e;
			if(e>s) s=e;
			a[e][2]+=1;
		}
		for(j=1;j<=s;j++)
		{
			e=min(a[j][2],a[j][1]);
			c-=e;
			b-=e;
			a[j][2]-=e;
			a[j][1]-=e;
			if(c<b)
			{
				t+=a[j][1]/2;
			}
			else
			{
				t+=a[j][2]/2;
			}
		}
		if(t>(l-r)/2&&t>(r-l)/2) t=max((l-r)/2,(r-l)/2);
		z=max(b,c)-t;
		cout<<z<<endl;
	}
	return 0; 
}