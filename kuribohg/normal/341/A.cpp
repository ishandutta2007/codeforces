#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
LL a[MAXN],ans,sum,g;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans+=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum+=a[i],ans+=2LL*((LL)i*a[i]-sum);
    g=gcd(ans,n);
    ans/=g,n/=g;
    printf("%I64d %d\n",ans,n);
    return 0;
}