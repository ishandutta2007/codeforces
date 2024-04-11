#include <bits/stdc++.h>
using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n,i,j,s=0,rz=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sumneg=0;
        int sumpoz=0;
        s=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            s+=v[i];
            if(v[i]>0)
                sumpoz+=v[i];
            else
                sumneg+=(-v[i]);
        }
        if(s==0)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        sort(v+1,v+n+1);
        if(sumpoz<sumneg)
        {
            for(i=1;i<=n;++i)
                cout<<v[i]<<' ';
        }
        else
            for(i=n;i>=1;--i)
                cout<<v[i]<<' ';
        cout<<'\n';
    }
}