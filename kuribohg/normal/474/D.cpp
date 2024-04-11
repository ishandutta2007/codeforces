#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MOD=1000000007; 
int n,T,k,f[100010];
int main()
{
    scanf("%d%d",&T,&k);
    n=100000;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        if(i>=k) f[i]=(f[i]+f[i-k])%MOD;
    }
    for(int i=1;i<=n;i++) f[i]=(f[i]+f[i-1])%MOD;
    for(int i=1,a,b;i<=T;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",(f[b]-f[a-1]+MOD)%MOD);
    }
    return 0;
}