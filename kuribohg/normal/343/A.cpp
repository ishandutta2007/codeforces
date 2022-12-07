#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL a,b,ans;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    ans+=a/b;
    return gcd(b,a%b);
}
int main()
{
    scanf("%I64d%I64d",&a,&b);
    gcd(a,b);
    printf("%I64d\n",ans);
    return 0;
}