#include <bits/stdc++.h>
using namespace std;
long long v[103][103];
vector<int>vc;
long long solve ()
{
    sort(vc.begin(),vc.end());
    if(vc.size()==1)
        return 0;
    long long rzc=vc[1]-vc[0];
    for(int i=2;i<vc.size();++i)
    {
        rzc+=vc[i]-vc[1];
    }
    return rzc;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        for(i=1;i<=(n+1)/2;++i)
            for(j=1;j<=(m+1)/2;++j)
            {
                vc.clear();
                vc.push_back(v[i][j]);
                if(i!=n-i+1)
                    vc.push_back(v[n-i+1][j]);
                if(j!=m-j+1)
                    vc.push_back(v[i][m-j+1]);
                if(i!=n-i+1)
                    if(j!=m-j+1)
                        vc.push_back(v[n-i+1][m-j+1]);
                ans+=solve();
            }
        cout<<ans<<'\n';
    }
    return 0;
}