#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,rz=0,dr,tot,m,obj,st,cnt=0,cnti=0,s=0,nri=0,b=0,a2,b2,a3,b3;
    char c;
    cin>>n;
    cout<<0<<' '<<0<<endl;
    cout.flush();
    st=0;
    dr=1000000000;
    cin>>c>>c>>c>>c>>c;
    char modl=c;
    for(i=1;i<n;++i)
    {
        cout<<0<<' '<<(st+dr)/2<<endl;
        cin>>c>>c>>c>>c>>c;
        cout.flush();
        if(c!=modl)
            dr=(st+dr)/2;
        else
            st=(st+dr)/2;
    }
    if((st+dr/2)*2==st+dr)
        cout<<0<<' '<<(st+dr)/2<<' '<<1<<' '<<(st+dr)/2<<endl;
    else if ((st+dr)/2+2<=1000000000)
        cout<<1<<' '<<(st+dr)/2+1<<' '<<3<<' '<<(st+dr)/2+2<<endl;
    else
        cout<<1<<' '<<(st+dr)/2<<' '<<3<<' '<<(st+dr)/2-1<<endl;
    cout.flush();
    return 0;
}