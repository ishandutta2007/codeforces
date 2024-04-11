#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
typedef long long LL;
const int MAXN=100010;
set<int> S;
int n,m,a[MAXN],G[MAXN],f[MAXN],p,g=1;
LL ans=-1e18,con;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int calc(int n)
{
    int nn=n,p,con=0;
    for(int i=2;i*i<=nn;i++)
        if(n%i==0)
        {
            if(S.count(i)) p=-1;
            else p=1;
            n/=i,con+=p;
            while(n%i==0) n/=i,con+=p;
        }
    if(n>1)
    {
        if(S.count(n)) con--;
        else con++;
    }
    return con;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&a[0]),S.insert(a[0]);
    G[1]=a[1];
    for(int i=2;i<=n;i++) G[i]=gcd(G[i-1],a[i]);
    G[n+1]=1;
    for(int i=1;i<=n;i++) f[i]=calc(a[i]);
    //for(int i=1;i<=n;i++) cout<<G[i]<<endl;
    for(int i=1;i<=n;i++) con+=f[i];
    ans=max(ans,con);
    for(int i=n;i>=1;i--)
    {
        if(G[i+1]==G[i]) continue;
        else if(calc(G[i]/g)<0) ans-=(LL)i*(LL)calc(G[i]/g),g=G[i];
    }
    printf("%I64d\n",ans);
    return 0;
}