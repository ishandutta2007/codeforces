#include<bits/stdc++.h>
using namespace std;
bool prime(long long x)
{
    for(long long i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
bool ok()
{
long long a,b;
scanf("%lld%lld",&a,&b);
if(a-b!=1)return 0;
return prime(a+b);
}
int main()
{
int t;
scanf("%i",&t);
for(int i=1;i<=t;i++)
    if(ok())printf("YES\n");
    else printf("NO\n");
return 0;
}