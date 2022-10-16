#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,rz=0,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        s=0;
        if(k!=0)
        {
            for(i=n;i>=n-k;--i)
            {
                s+=v[i];
            }
            cout<<s<<'\n';
            continue;
        }
        cout<<v[n]-v[1]<<'\n';
    }
    return 0;
}