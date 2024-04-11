#include <bits/stdc++.h>
using namespace std;
int v[1003];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,rz=0,m;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]==k)
                ++cnt;
        }
        sort(v+1,v+n+1);
        if(v[1]==v[n] && v[1]==k)
        {
            cout<<0<<'\n';
            continue;
        }
        long long s=0;
        for(i=1;i<=n;++i)
            s+=v[i];
        if(s==k*n || cnt!=0)
            cout<<1<<'\n';
        else
            cout<<2<<'\n';
    }
    return 0;
}