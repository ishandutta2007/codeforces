#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1000000000000000000LL;
const int MOD=1000000007;
const int MAXN=30010;
int n,k,t,v[MAXN],w[MAXN],L[MAXN],R[MAXN],tot;
vector<int> questions;
struct Seg
{
    int l,r;
    vector<pair<int,int> > items;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(T[x].l==T[x].r) return;
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
}
void Add(int x,int l,int r,int v,int w)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].items.push_back(make_pair(v,w));
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) Add(x<<1,l,r,v,w);
    else if(l>mid) Add(x<<1|1,l,r,v,w);
    else Add(x<<1,l,mid,v,w),Add(x<<1|1,mid+1,r,v,w);
}
LL f[50][1010],ans[MAXN];
void DFS(int x,int d)
{
    for(int i=0;i<=k;i++) f[d][i]=f[d-1][i];
    int len=T[x].items.size();
    for(int i=0;i<len;i++)
    {
        LL v=T[x].items[i].first;
        int w=T[x].items[i].second;
        for(int j=k;j>=0;j--)
            if(j+w<=k) f[d][j+w]=max(f[d][j+w],f[d][j]+v);
    }
    if(T[x].l==T[x].r)
    {
        LL p=1,res=0;
        for(int i=1;i<=k;i++)
            res=(res+p*f[d][i])%MOD,p=(p*10000019)%MOD;
        ans[T[x].l]=res;
    }
    else
    {
        DFS(x<<1,d+1);
        DFS(x<<1|1,d+1);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    tot=n;
    for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]),L[i]=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int op,x,y;
        scanf("%d",&op);
        if(op==1) scanf("%d%d",&x,&y),++tot,v[tot]=x,w[tot]=y,L[tot]=i;
        else if(op==2) scanf("%d",&x),R[x]=i;
        else questions.push_back(i);
    }
    for(int i=1;i<=tot;i++)
        if(!R[i]) R[i]=t;
    MakeTree(1,1,t);
    for(int i=1;i<=tot;i++) Add(1,L[i],R[i],v[i],w[i]);
    DFS(1,1);
    for(int i=0;i<(int)questions.size();i++)
        printf("%I64d\n",ans[questions[i]]);
    return 0;
}