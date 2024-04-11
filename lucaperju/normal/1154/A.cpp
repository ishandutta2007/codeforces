#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,n,i,j,mn=100003LL*100003LL,k=0,mx=99999999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3,pz=1;
    int i1=-1,j1=-1,i2=-1,j2=-1;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    mx=max(max(a,b),max(c,d));
    {
        if(mx==a)
            cout<<mx-b<<' '<<mx-c<<' '<<mx-d;
        else
        if(mx==b)
            cout<<mx-a<<' '<<mx-c<<' '<<mx-d;
        else
        if(mx==c)
            cout<<mx-b<<' '<<mx-a<<' '<<mx-d;
        else
        if(mx==d)
            cout<<mx-b<<' '<<mx-c<<' '<<mx-a;
    }
    return 0;
}