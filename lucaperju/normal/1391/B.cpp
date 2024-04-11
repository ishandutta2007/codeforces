#include <bits/stdc++.h>
using namespace std;
char v[103][103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        }
        int cnt=0;
        for(i=1;i<n;++i)
        {
            if(v[i][m]=='R')
                ++cnt;
        }
        for(i=1;i<m;++i)
        {
            if(v[n][i]=='D')
                ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}