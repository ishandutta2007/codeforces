#include <bits/stdc++.h>

using namespace std;
int spr[200005],spg[200005],spb[200005];
int main()
{
    int i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>t;
    while(t--)
    {
        int w,b;
        cin>>b>>w;
        int nrp=min(w,b);
        int ram=max(w,b)-nrp;
        if(2*nrp+1<ram)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i=1;i<=nrp*2;++i)
        {
            cout<<2<<' '<<i+1<<'\n';
            ++i;
            cout<<2<<' '<<i+1<<'\n';
        }
        if(!ram)
            continue;
        if(w>b)
        {
            cout<<2<<' '<<nrp*2+2<<'\n';
            --ram;
            i=3;
        }
        else
        {
            cout<<2<<' '<<1<<'\n';
            --ram;
            i=2;
        }
        for(;i<=nrp*2+1 && ram;i+=2)
        {
            cout<<1<<' '<<i<<'\n';
            --ram;
            if(!ram)
                break;
            cout<<3<<' '<<i<<'\n';
            --ram;
        }
    }
    return 0;
}