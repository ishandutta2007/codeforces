#include <bits/stdc++.h>
using namespace std;
int v[100005];
int rz[100005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
        int cnt=0;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        j=0;
        for(i=2;i<=n;i+=2)
        {
            rz[i]=v[++j];
        }
        for(i=1;i<=n;i+=2)
            rz[i]=v[++j];
        for(i=2;i<n;++i)
        {
            if(rz[i]<rz[i-1] && rz[i]<rz[i+1])
                ++cnt;
        }
        cout<<cnt<<'\n';
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
       // cout<<'\n';
    return 0;
}