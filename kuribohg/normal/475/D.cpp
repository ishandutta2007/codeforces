#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<functional>
#include<iterator>
using namespace std;
typedef long long LL;
const int MAXN=100010;
map<int,LL> ans;
int n,a[MAXN],T,q,Log[MAXN],ST[500010][21];
int L[MAXN<<2],R[MAXN<<2],G[MAXN<<2];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
/*void maketree(int x,int l,int r)
{
    L[x]=l,R[x]=r;
    if(L[x]==R[x]) {G[x]=a[L[x]];return;}
    int m=(L[x]+R[x])>>1;
    maketree(x<<1,l,m);
    maketree(x<<1|1,m+1,r);
    G[x]=gcd(G[x<<1],G[x<<1|1]);
}*/
int query(int x,int l,int r)
{
    int len=(r-l+1);
    return gcd(ST[l][Log[len]],ST[r+1-(1<<Log[len])][Log[len]]);
}
void work(int x)
{
    int p=a[x],rr=x;
    while(rr<=n)
    {
        int l=rr,r=n+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            int g=query(1,x,mid);
            if(g<p) r=mid;
            else l=mid+1;
        }
        ans[p]+=(LL)(r-rr);
        rr=r,p=query(1,x,r);
    }
}
int main()
{
    scanf("%d",&n);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[++n]=1;
    for(int i=1;i<=n;i++) ST[i][0]=a[i];
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)
            ST[j][i]=gcd(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
    n--;
    for(int i=1;i<=n;i++)
        work(i);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&q);
        printf("%I64d\n",ans[q]);
    }
    return 0;
}