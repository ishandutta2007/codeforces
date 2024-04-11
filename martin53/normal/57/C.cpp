#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7;
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2==0)return 1LL*c*c%mod;
    return 1LL*c*c%mod*a%mod;
}
int fact(int n)
{
    int res=1;
    for(int i=2;i<=n;i++)
    {
        res=(1LL*res*i)%mod;
    }
    return res;
}
int main()
{
int n;
scanf("%i",&n);
int ans=2LL*fact(2*n-1)*my_pow(fact(n-1),mod-2)%mod*my_pow(fact(n),mod-2)%mod;
ans=(ans-n+mod)%mod;
printf("%i\n",ans);
return 0;
}