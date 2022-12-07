#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
LL qpow(LL x,LL n,LL MOD)
{
    LL con=1,p=x;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
LL p,k;
int main()
{
    scanf("%I64d%I64d",&p,&k);
    if(k==0) {printf("%I64d\n",qpow(p,p-1,MOD));return 0;}
    if(k==1) {printf("%I64d\n",qpow(p,p,MOD));return 0;}
    int x=1;
    while(qpow(k,x,p)!=1) x++;
    printf("%I64d\n",qpow(p,(p-1)/x,MOD));
    return 0;
}