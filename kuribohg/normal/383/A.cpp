#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n,a[200010],p[2];
LL ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]++;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==1) p[a[i]]--;
        else ans+=(LL)p[a[i]^1];
    }
    printf("%I64d\n",ans);
    return 0;
}