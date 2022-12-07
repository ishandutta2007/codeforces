#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=10007;
const int MAXN=100010;
int n,a[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) ans=(ans+(LL)a[i]*a[n+1-i]%MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}