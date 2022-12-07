#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MOD=1000000007;
int n,k,a,b,f[5010],s[5010],l,r,ans;
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    f[a]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==b) continue;
            if(j>b&&a<b) continue;
            if(j<b&&a>b) continue;
            if(a<b) l=max(0,2*j-b)+1,r=b;
            else l=b+1,r=min(n+1,2*j-b);
            s[l]=(s[l]+f[j])%MOD;
            s[r]=(s[r]-f[j]+MOD)%MOD;
            s[j]=(s[j]-f[j]+MOD)%MOD;
            s[j+1]=(s[j+1]+f[j])%MOD;
        }
        for(int j=0;j<=n;j++) f[j]=0;
        for(int j=1;j<=n;j++) f[j]=(f[j-1]+s[j])%MOD;
        for(int j=0;j<=n;j++) s[j]=0;
    }
    for(int i=1;i<=n;i++) ans=(ans+f[i])%MOD;
    printf("%d\n",ans);
    return 0;
}