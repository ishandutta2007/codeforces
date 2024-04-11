#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=200010;
const int MOD=1000000006;
int n,x,p[MAXN],c[MAXN];
LL pre[MAXN],suf[MAXN],ans=1;
map<int,int> M;
LL qpow(LL x,LL n,LL MOD)
{
    LL con=1,p=x;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
int main()
{
    scanf("%d",&n);
    while(n--) scanf("%d",&x),M[x]++;
    ++n;
    for(map<int,int>::iterator it=M.begin();it!=M.end();++it)
    {
        ++n;
        p[n]=it->first,c[n]=it->second;
    }
    pre[0]=1;
    for(int i=1;i<=n;i++)
        pre[i]=(pre[i-1]*(c[i]+1))%MOD;
    suf[n+1]=1;
    for(int i=n;i>=1;i--)
        suf[i]=(suf[i+1]*(c[i]+1))%MOD;
    for(int i=1;i<=n;i++)
        ans=(ans*qpow(p[i],(((LL)c[i]*(c[i]+1)/2LL)%MOD*(pre[i-1]*suf[i+1]%MOD))%MOD,MOD+1))%(MOD+1);
    printf("%I64d\n",ans);
    return 0;
}