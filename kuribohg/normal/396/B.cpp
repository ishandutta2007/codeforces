#include<iostream>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
unsigned long long T;
unsigned long long n;
struct frac
{
    unsigned long long u,d;
};
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
frac operator+(const frac &a,const frac &b)
{
    frac c;
    c.d=a.d*b.d;
    c.u=a.u*b.d+a.d*b.u;
    unsigned long long g=gcd(c.d,c.u);
    c.d/=g,c.u/=g;
    return c;
}
frac operator-(const frac &a,const frac &b)
{
    frac c;
    c.d=a.d*b.d;
    c.u=a.u*b.d-a.d*b.u;
    unsigned long long g=gcd(c.d,c.u);
    c.d/=g,c.u/=g;
    return c;
}
frac operator*(const frac &a,const unsigned long long &b)
{
    frac c;
    c.d=a.d;
    c.u=a.u*b;
    unsigned long long g=gcd(c.d,c.u);
    c.d/=g,c.u/=g;
    return c;
}
unsigned long long qpow(unsigned long long a,unsigned long long n,unsigned long long MOD)
{
    unsigned long long p=a%MOD,con=1;
    while(n>0)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
bool witness(unsigned long long n,unsigned long long p)
{
    unsigned long long u=n-1,t=0,pre;
    while(!(u&1)) u>>=1,t++;
    unsigned long long x=qpow(p%n,u,n);
    for(unsigned long long i=1;i<=t;i++)
    {
        pre=x,x=(x*x)%n;
        if(x==1&&pre!=1&&pre!=n-1) return false;
    }
    return x==1;
}
bool is_prime(unsigned long long n)
{
    unsigned long long prime[5]={2,3,7,61,24251};
    if(find(prime,prime+5,n)!=prime+5) return true;
    if(n==1||!(n&1)) return false;
    for(unsigned long long i=0;i<5;i++)
        if(!witness(n,prime[i])) return false;
    return true;
}
int main()
{
    scanf("%I64d",&T);
    for(unsigned long long cas=1;cas<=T;cas++)
    {
        scanf("%I64d",&n);
        unsigned long long next=n+1,pre=n;
        while(!is_prime(next)) next++;
        while(!is_prime(pre)) pre--;
        frac a,b,c;
        a.u=1,a.d=2,b.u=1,b.d=pre;
        c=a-b;
        b.d=pre*next;
        b=b*(n-pre+1);
        b.u<<=1,b.d<<=1;
        c.u*=b.d/c.d;
        c.d=b.d;
        c.u+=b.u;
        unsigned long long g=gcd(c.u,c.d);
        c.u/=g,c.d/=g;
        printf("%I64d/%I64d\n",c.u,c.d);
    }
    return 0;
}