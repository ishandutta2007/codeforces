#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL a1,b1,a2,b2,L,R;
LL myabs(LL x)
{
    if(x<0) return -x;
    return x;
}
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0) {x=1,y=0;return;}
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
LL mul(LL x,LL n,LL MOD)
{
    LL con=0,p=x;
    while(n)
    {
        if(n&1) con=(con+p)%MOD;
        p=(p+p)%MOD;
        n>>=1;
    }
    return con;
}
int main()
{
    int flag=0;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    if(b1>b2) flag=0;
    else flag=1;
    LL c=myabs(b1-b2);
    LL g=gcd(a1,a2);
    if(c%g!=0) {puts("0");return 0;}
    LL x=0,y=0;
    exgcd(a1,a2,x,y);
    x*=c/g,y*=c/g;
    LL lcm=0;
    lcm=a1/gcd(a1,a2)*a2;
    LL delta=0;
    L=max(L,b1);
    L=max(L,b2);
    delta=(L%lcm+lcm)%lcm-L;
    L+=delta+lcm,R+=delta+lcm;
    LL m=0;
    if(flag==0) m=((mul(y%lcm,a2,lcm)+b2)%lcm+lcm)%lcm;
    else m=((mul(x%lcm,a1,lcm)+b1)%lcm+lcm)%lcm;
    cout<<max(0LL,(R-m)/lcm-(L-1-m)/lcm)<<endl;
    return 0;
}