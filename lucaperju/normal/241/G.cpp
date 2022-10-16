#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,rz=0,tot,m,obj,st,cnt=0,cnti=0,s=0,nri=0,a[4],b=0,c=0,a2,b2,a3,b3;
    n=305;
    m=1000000;
    cout<<n<<'\n';
    int r=m,x=m/2;
    cout<<x<<' '<<r<<'\n';
    x+=35300;
    for(i=1;i<n-1;++i)
    {
        x+=2*(n-i)+1;
        r=n-i;
        cout<<x<<' '<<r<<'\n';
    }
    cout<<m<<' '<<m<<'\n';
    return 0;
}