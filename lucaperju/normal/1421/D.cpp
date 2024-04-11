#include <bits/stdc++.h>
using namespace std;
long long c[10];
int main()/// incredibil ce jeg de problema
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        for(i=1;i<=6;++i)
            cin>>c[i];
        j=10;
        while(j--)
        {
            c[1]=min(c[1],c[2]+c[6]);
            for(i=2;i<=5;++i)
                c[i]=min(c[i],c[i-1]+c[i+1]);
            c[6]=min(c[6],c[1]+c[5]);
        }
        long long s=0;
        if(x==0)
        {
            if(y>0)
                cout<<y*1LL*c[2]<<'\n';
            else
                cout<<(-y)*1LL*c[5]<<'\n';
            continue;
        }
        if(y==0)
        {
            if(x>0)
                cout<<x*1LL*c[6]<<'\n';
            else
                cout<<(-x)*1LL*c[3]<<'\n';
            continue;
        }
        if(x>0 && y<0)
        {
            cout<<c[6]*1LL*x+c[5]*1LL*(-y)<<'\n';
        }
        if(x<0 && y>0)
        {
            cout<<c[2]*1LL*y+c[3]*1LL*(-x)<<'\n';
        }
        if(x>0 && y>0)
        {
            if(x>y)
                cout<<c[1]*1LL*y+c[6]*1LL*(x-y)<<'\n';
            else
                cout<<c[1]*1LL*x+c[2]*1LL*(y-x)<<'\n';
        }
        if(x<0 && y<0)
        {
            x=-x;
            y=-y;
            if(x>y)
                cout<<c[4]*1LL*y+c[3]*1LL*(x-y)<<'\n';
            else
                cout<<c[4]*1LL*x+c[5]*1LL*(y-x)<<'\n';
        }
    }
    return 0;
}