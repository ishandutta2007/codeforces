#include <bits/stdc++.h>

using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int cmmmc (int a, int b)
{
    return a*b/(cmmdc(a,b));
}
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz,a1,b1,a2,b2,a3,b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    if(b2==0)
    {
        cout<<"Hermione";
        return 0;
    }
    if(a2==0)
    {
        cout<<"Ron";
        return 0;
    }
    if(b1==0)
    {
        cout<<"Hermione";
        return 0;
    }
    if(a1==0)
    {
        cout<<"Ron";
        return 0;
    }
    if(b3==0)
    {
        cout<<"Hermione";
        return 0;
    }
    if(a3==0)
    {
        cout<<"Ron";
        return 0;
    }
    long long cr=cmmdc(a1,b1);
    a1/=cr;
    b1/=cr;
    cr=cmmdc(a2,b2);
    a2/=cr;
    b2/=cr;
    cr=cmmdc(a3,b3);
    a3/=cr;
    b3/=cr;
    cr=cmmmc(b1,a2);
    a1*=cr/b1;
    b1=cr;
    b2*=cr/a2;
    a2=cr;
    cr=cmmmc(b2,a3);
    b3*=cr/a3;
    cr/=b2;
    a1*=cr;
    b1*=cr;
    a2*=cr;
    if(a1>=b3)
        cout<<"Hermione";
    else
        cout<<"Ron";
    return 0;
}