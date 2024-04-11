#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MOD=1000000007;
int n,m,h,f[1000010],ans,s,l,r;
int main()
{
    scanf("%d%d",&n,&m);
    for(h=1;;h++) if(h*(h+1)>2*(n+m)) break;
    h--;
    s=(1+h)*h/2;
    f[0]=1;
    for(int i=1;i<=h;i++)
        for(int j=n+m;j>=0;j--)
            if(j-i>=0) f[j]=(f[j]+f[j-i])%MOD;
    l=n,r=max(s-m,0);
    if(l>r) swap(l,r);
    for(int i=l;i<=r;i++) ans=(ans+f[i])%MOD;
    printf("%d\n",ans);
    return 0;
}