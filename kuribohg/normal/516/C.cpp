#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,m,Log[MAXN],l[MAXN],r[MAXN],L[MAXN],R[MAXN],T[MAXN<<2],sub[MAXN][2][2];
LL d[MAXN],s[MAXN],p[MAXN],A[MAXN],ans[MAXN];
void MakeTree(int x,int l,int r)
{
    if(l==r) {T[x]=l;return;}
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
    if(A[T[x<<1]]>A[T[x<<1|1]]) T[x]=T[x<<1];
    else T[x]=T[x<<1|1];
}
void Change(int x,int l,int r,int pos,int tar)
{
    if(l==r) {T[x]=tar;return;}
    int mid=(l+r)>>1;
    if(pos<=mid) Change(x<<1,l,mid,pos,tar);
    else Change(x<<1|1,mid+1,r,pos,tar);
    if(A[T[x<<1]]>A[T[x<<1|1]]) T[x]=T[x<<1];
    else T[x]=T[x<<1|1];
}
int Query(int x,int l,int r,int L,int R)
{
    if(l==L&&r==R) return T[x];
    int mid=(l+r)>>1;
    if(R<=mid) return Query(x<<1,l,mid,L,R);
    else if(L>mid) return Query(x<<1|1,mid+1,r,L,R);
    else
    {
        int lcon=Query(x<<1,l,mid,L,mid);
        int rcon=Query(x<<1|1,mid+1,r,mid+1,R);
        if(A[lcon]>A[rcon]) return lcon;
        else return rcon;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&d[i]),d[i]<<=1;
    for(int i=2;i<=n;i++) s[i]=s[i-1]+p[i-1];
    s[n+1]=s[n]+p[n];
    for(int i=n+2;i<=n+n;i++) s[i]=s[i-1]+p[i-n-1];
    for(int i=n+1;i<=n+n;i++) d[i]=d[i-n];
    for(int i=1;i<=m;i++) scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=m;i++)
        if(l[i]<=r[i]) L[i]=r[i]+1,R[i]=l[i]+n-1;
        else L[i]=r[i]+1,R[i]=l[i]-1;
    n<<=1;
    A[n+1]=-1000000000000000000LL;
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++) A[i]=d[i]+s[i];
    MakeTree(1,1,n);
    for(int i=1;i<=m;i++)
    {
        sub[i][0][0]=Query(1,1,n,L[i],R[i]);
        Change(1,1,n,sub[i][0][0],n+1);
        sub[i][1][0]=Query(1,1,n,L[i],R[i]);
        Change(1,1,n,sub[i][0][0],sub[i][0][0]);
    }
    for(int i=1;i<=n;i++) A[i]=d[i]-s[i];
    MakeTree(1,1,n);
    for(int i=1;i<=m;i++)
    {
        sub[i][0][1]=Query(1,1,n,L[i],R[i]);
        Change(1,1,n,sub[i][0][1],n+1);
        sub[i][1][1]=Query(1,1,n,L[i],R[i]);
        Change(1,1,n,sub[i][0][1],sub[i][0][1]);
    }
    for(int i=1;i<=m;i++)
    {
        ans[i]=-1000000000000000000LL;
        if(sub[i][0][0]!=sub[i][0][1]) ans[i]=max(ans[i],d[sub[i][0][0]]+s[sub[i][0][0]]+d[sub[i][0][1]]-s[sub[i][0][1]]);
        if(sub[i][1][0]!=sub[i][0][1]) ans[i]=max(ans[i],d[sub[i][1][0]]+s[sub[i][1][0]]+d[sub[i][0][1]]-s[sub[i][0][1]]);
        if(sub[i][0][0]!=sub[i][1][1]) ans[i]=max(ans[i],d[sub[i][0][0]]+s[sub[i][0][0]]+d[sub[i][1][1]]-s[sub[i][1][1]]);
        if(sub[i][1][0]!=sub[i][1][1]) ans[i]=max(ans[i],d[sub[i][1][0]]+s[sub[i][1][0]]+d[sub[i][1][1]]-s[sub[i][1][1]]);
    }
    for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
    return 0;
}