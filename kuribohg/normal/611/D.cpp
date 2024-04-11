#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1000000007;
typedef unsigned long long ULL;
int n,f[5010][5010],ans;
char a[5010];
ULL Hash[5010],PowP[5010],p=131;
ULL getHash(int x,int l)
{
    return Hash[x]-Hash[x+l]*PowP[l];
}
int main()
{
    scanf("%d%s",&n,a+1);
    PowP[0]=1;
    for(int i=1;i<=n;i++) PowP[i]=PowP[i-1]*p;
    for(int i=n;i>=1;i--) Hash[i]=Hash[i+1]*p+(ULL)(a[i]-'0');
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) f[i][j]=(f[i][j]+f[i][j-1])%MOD;
        for(int j=i;j<n;j++)
        {
            int len=j-i+1;
            int l=0,r=len;
            if(a[j+1]=='0') continue;
            if(j+len>n) continue;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(getHash(i,mid)==getHash(j+1,mid)) l=mid;
                else r=mid-1;
            }
            if(l!=len&&a[i+l]<a[j+1+l]) f[j+1][j+len]=(f[j+1][j+len]+f[i][j])%MOD;
            else f[j+1][j+len+1]=(f[j+1][j+len+1]+f[i][j])%MOD;
        }
    }
    for(int i=1;i<=n;i++)
        ans=(ans+f[i][n])%MOD;
    printf("%d\n",ans);
    return 0;
}