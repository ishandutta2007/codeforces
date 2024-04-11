#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
LL n,a,b,f[100010],sub;
bool p;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    n*=6;
    if(a*b>=n) {printf("%I64d\n%I64d %I64d\n",a*b,a,b);return 0;}
    if(a<b) {swap(a,b);p=true;}
    for(LL i=1;i*i<=n;i++) f[i]=(n+i-1)/i;
    for(LL i=1;i*i<=n;i++)
        if(i>=b&&f[i]>=a)
            if(sub==0||i*f[i]<sub*f[sub]) sub=i;
    printf("%I64d\n",sub*f[sub]);
    if(p) printf("%I64d %I64d\n",sub,f[sub]);
    else printf("%I64d %I64d\n",f[sub],sub);
    return 0;
}