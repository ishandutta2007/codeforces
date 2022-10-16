#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    long long i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int xmn=-100000,xmx=100000,ymn=-100000,ymx=100000;
        for(i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            int a;
            cin>>a;
            if(a==0)
                xmn=max(xmn,x);
            cin>>a;
            if(a==0)
                ymx=min(ymx,y);
            cin>>a;
            if(a==0)
                xmx=min(xmx,x);
            cin>>a;
            if(a==0)
                ymn=max(ymn,y);
        }
        if(xmn<=xmx && ymn<=ymx)
        {
            cout<<"1 "<<xmn<<' '<<ymn<<'\n';
        }
        else
            cout<<0<<'\n';
    }
    return 0;
}