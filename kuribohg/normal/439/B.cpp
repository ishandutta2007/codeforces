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
LL x,a[100010],ans;
int main()
{
    scanf("%d%I64d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ans+=x*a[i];
        if(x>1) x--;
    }
    printf("%I64d\n",ans);
    return 0;
}