#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n;
LL a[500010],sum,s[500010],sp[500010],p,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),sum+=a[i];
    if(sum%3!=0) {puts("0");return 0;}
    sum/=3;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n;i>=1;i--) sp[i]=sp[i+1]+a[i];
    for(int i=n-1;i>=1;i--)
    {
        if(s[i]==sum) ans+=p;
        if(sp[i+1]==sum) p++;
    }
    printf("%I64d\n",ans);
    return 0;
}