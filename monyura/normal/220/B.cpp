#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<double,double> pdd;

struct node
{
    int x,y;
    int cnt;
    node *left,*right;
    void init(int x0,int y0)
    {
        left=right=0;
        x=x0;
        y=y0;
        cnt=1;
    }
} BUFF[400200];
int bcnt=0;

void recalc(node *v)
{
    if (v==0) return;
    v->cnt=1;
    if (v->left)
        v->cnt+=v->left->cnt;
    if (v->right)
        v->cnt+=v->right->cnt;
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

node *Add(node *v,int x,int y)
{
    node *L,*R,*added=BUFF+bcnt++;
    added->init(x,y);
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

int getGreatEq(node *v,int x)
{
    if (v==0) return 0;
    if (v->x>=x)
        return getGreatEq(v->left,x) + (v->right ? v->right->cnt : 0) +1;
    return getGreatEq(v->right,x);
}

void run()
{
    int n,m;
    cin>>n>>m;
    int A[100100];
    vector<int> vec[100100];
    vector<pii> q[100100];
    int Ans[100100];
    rep(i,0,n)
        scanf("%d",A+i);
    rep(i,0,m)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        --l;--r;
        q[r].push_back(pii(l,i));
    }
    node *T=0;
    node *Gr=0;
    rep(i,0,n)
    {
        int a=A[i];
        if (a<=n)
        {
        if (vec[a].size()>=a+1)
                Gr=remove(Gr,vec[a][vec[a].size()-(a+1)]);
            
            if (vec[a].size()>=a)
                T=remove(T,vec[a][vec[a].size()-a]);
            vec[a].push_back(i);
            if (vec[a].size()>=a)
                T=Add(T,vec[a][vec[a].size()-a],rand());

            //vec[a].push_back(i);
            if (vec[a].size()>=a+1)
                Gr=Add(Gr,vec[a][vec[a].size()-(a+1)],rand());
        }
        rep(j,0,q[i].size())
        {
            int res=getGreatEq(T,q[i][j].first) - getGreatEq(Gr,q[i][j].first);
            Ans[q[i][j].second]=res;
        }
    }
    rep(i,0,m)
        printf("%d\n",Ans[i]);
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/