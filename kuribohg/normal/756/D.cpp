#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,tot,f[5010][30],sum[5010];
LL C[5010];
char str[5010],s[5010];
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
    scanf("%d%s",&n,str);
    s[tot=1]=str[0];
    for(int i=1;i<n;i++)
        if(str[i]!=str[i-1]) s[++tot]=str[i];
    C[0]=1;
    for(int i=1;i<n;i++)
        C[i]=((C[i-1]*(n-i))%MOD*qpow(i,MOD-2,MOD))%MOD;
    for(int i=1;i<=tot;i++)
    {
        int o=s[i]-'a';
        for(int j=i;j>1;j--)
        {
            sum[j]=(sum[j]-f[j][o]+MOD)%MOD;
            f[j][o]=(sum[j-1]-f[j-1][o]+MOD)%MOD;
            sum[j]=(sum[j]+f[j][o])%MOD;
        }
        if(!f[1][o]) f[1][o]=1,sum[1]=(sum[1]+1)%MOD;
    }
    int ans=0;
    for(int i=1;i<=tot;i++)
        ans=(ans+(LL)sum[i]*C[i-1])%MOD;
    printf("%d\n",ans);
    return 0;
}