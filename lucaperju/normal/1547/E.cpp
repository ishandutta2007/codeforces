#include <bits/stdc++.h>
using namespace std;
int v[300005],st[300005],dr[300005];
int a[300005]; // cuz ofc the AC's are given on two lines
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            v[i]=st[i]=dr[i]=0;
        for(i=1;i<=m;++i)
            cin>>a[i];
        for(i=1;i<=m;++i)
        {
            int b;
            cin>>b;
            v[a[i]]=b;
        }
        st[0]=dr[n+1]=1100000000;
        for(i=1;i<=n;++i)
            st[i]=min(st[i-1]+1,v[i]+(v[i]==0)*1100000000);
        for(i=n;i>=1;--i)
            dr[i]=min(dr[i+1]+1,v[i]+(v[i]==0)*1100000000);
        for(i=1;i<=n;++i)
            cout<<min(st[i],dr[i])<<' ';
        cout<<'\n';
    }
    return 0;
}