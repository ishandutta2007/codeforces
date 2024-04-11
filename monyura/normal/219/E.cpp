#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <functional>
#include <ctime>
#include <complex>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;++x)
#define all(a) (a).begin(),(a).end()

struct node
{
    int x,y;
    int val;
    int mx;
    int mxX;
    node *left,*right;
    void init(int x0,int y0,int val0)
    {
        left=right=0;
        x=x0;
        y=y0;
        val=val0;
        mx=val0;
        mxX=x;
    }
} BUFF[400200];
int bcnt=0;

void recalc(node *v)
{
    if (v==0) return;
    v->mx=v->val;
    v->mxX=v->x;
    if (v->left && ((v->left->mx-1)/2 > (v->mx-1)/2 || (v->left->mx-1)/2 == (v->mx-1)/2 && v->left->mxX  < v->mxX))
    {
        v->mx=v->left->mx;
        v->mxX=v->left->mxX;
    }
    if (v->right && ((v->right->mx-1)/2 > (v->mx-1)/2 || (v->right->mx-1)/2 == (v->mx-1)/2 && v->right->mxX < v->mxX))
    {
        v->mx=v->right->mx;
        v->mxX=v->right->mxX;
    }
}

node *merge(node *L,node *R)
{
    if (L==0) return R;
    if (R==0) return L;
    if (L->y > R->y)
    {
        L->right=merge(L->right,R);
        recalc(L);
        return L;
    }
    R->left=merge(L,R->left);
    recalc(R);
    return R;
}

void split(node *v,node* &L,node* &R,int x)
{
    if (v==0)
    {
        L=R=0;
        return;
    }
    if (v->x < x)
    {
        split(v->right,v->right,R,x);
        recalc(v);
        L=v;
        return;
    }
    split(v->left,L,v->left,x);
    recalc(v);
    R=v;
    return;
}

node *Add(node *v,int x,int y,int val)
{
    node *L,*R,*added=BUFF+bcnt++;
    added->init(x,y,val);
    split(v,L,R,x);
    L=merge(L,added);
    return merge(L,R);
}

node *remove(node *v,int x)
{
    node *L,*R,*del;
    split(v,L,R,x);
    split(R,del,R,x+1);
    return merge(L,R);
}

node* getMax(node *v)
{
    if (v->right==0) return v;
    return getMax(v->right);
}

node *find(node *v,int x)
{
    if (v==0) return 0;
    if (v->x==x) return v;
    if (v->x < x) return find(v->right,x);
    return find(v->left,x);
}

int car[1000001]={0};

set<int,greater<int> > st;


void splitOtr(node* &v,int a,int b,int pos)
{
    v=remove(v,a);
    if (a!=pos)
        v=Add(v,a,rand(),pos-a);
    if (b!=pos)
        v=Add(v,pos+1,rand(),b-pos);
    st.insert(pos);
}

void mergeOtr(node* &v,int pos)
{
    node *L,*R;
    split(v,L,R,pos);
    int a=pos;
    if (L!=0)
    {
        node *t=getMax(L);
        if (t->x+t->val==pos)
        {
            a=t->x;
            L=remove(L,t->x);
        }
    }
    int b=pos;
    node *t=find(R,pos+1);
    if (t)
    {
        b=t->x+t->val-1;
        R=remove(R,t->x);
    }
    v=merge(L,R);
    v=Add(v,a,rand(),b-a+1);
    st.erase(pos);
}

int main()
{
    int n,m;
    cin>>n>>m;
    node *T=0;
    T=Add(T,1,rand(),n);
    rep(i,0,m)
    {
        int t,id;
        scanf("%d%d",&t,&id);
        if (car[id]==0)
        {
            int a=T->mxX;
            int b=a+T->mx-1;
            int pos=(a+b)>>1;
            int dist=pos-a;
            if (a==1 && b==n)
                pos=1;
            else
            {
                if (st.find(1)==st.end())
                {
                    set<int,greater<int> >::reverse_iterator iter=st.rbegin();
                    if (*iter-2>=dist)
                    {
                        pos=1;
                        a=1;
                        b=*iter-1;
                        dist=b-a;
                    }
                }
                if (st.find(n)==st.end() && n-*st.begin()-1>dist)
                {
                    a=*st.begin()+1;
                    b=n;
                    pos=n;
                    dist=n-a;
                }
            }
            printf("%d\n",pos);
            splitOtr(T,a,b,pos);
            car[id]=pos;
        }
        else
        {
            mergeOtr(T,car[id]);
            car[id]=0;
        }
    }
    return 0;
}
/*
100 6
1 1
2 1
1 1
2 1
1 1
2 1

3 10
1 482990
1 825307
2 825307
1 503980
2 482990
1 574529
1 76498
2 503980
2 574529
1 53179

*/