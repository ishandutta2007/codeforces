#include <bits/stdc++.h>
using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long a,b,x,y,rz=0,n,root,m,w,i,j,k=0,pas=1<<15,sc=0,cnt=0,mn=0,nr1=0,nr2=0,mx=0,catc=0;
    cin>>n;
    for(i=1;i*i<=n;++i)
    {
        if(n%i==0 && cmmdc(i,n/i)==1)
            rz=n/i;
    }
    cout<<n/rz<<' '<<rz;
    return 0;
}