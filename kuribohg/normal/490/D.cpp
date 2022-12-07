#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
LL x1,y1,x2,y2,p,q,g,n,m,t12,t13,t22,t23,T12,T13,T22,T23;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
    p=x1*y1,q=x2*y2,g=gcd(p,q),m=p/g,n=q/g;
    while(n%2==0) n/=2,t12++;
    while(n%3==0) n/=3,t13++;
    while(m%2==0) m/=2,t22++;
    while(m%3==0) m/=3,t23++;
    if(n!=1||m!=1) {puts("-1");return 0;}
    T13=t23,T23=t13,T22=t12-t23,T12=t22-t13;
    if(T12<0||T22<0) g=min(T12,T22),T12-=g,T22-=g;
    if(T13<0||T23<0||T22<0||T12<0) {puts("-1");return 0;}
    for(int i=1;i<=T13;i++)
    {
        if(x1%3==0) {x1=x1*2/3;continue;}
        else if(y1%3==0) {y1=y1*2/3;continue;}
        else {puts("-1");return 0;}
    }
    for(int i=1;i<=T23;i++)
    {
        if(x2%3==0) {x2=x2*2/3;continue;}
        else if(y2%3==0) {y2=y2*2/3;continue;}
        else {puts("-1");return 0;}
    }
    for(int i=1;i<=T12;i++)
    {
        if(x1%2==0) {x1>>=1;continue;}
        else if(y1%2==0) {y1>>=1;continue;}
        else {puts("-1");return 0;}
    }
    for(int i=1;i<=T22;i++)
    {
        if(x2%2==0) {x2>>=1;continue;}
        else if(y2%2==0) {y2>>=1;continue;}
        else {puts("-1");return 0;}
    }
    printf("%I64d\n",T12+T13+T22+T23);
    printf("%I64d %I64d\n%I64d %I64d\n",x1,y1,x2,y2);
    return 0;
}