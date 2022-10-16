#include <bits/stdc++.h>
using namespace std;
int v[103][103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                v[i][j]=0;
        }
        for(i=1;i<=n;++i)
        {
            v[i][i]=v[i][i+1]=1;
        }
        v[n][1]=1;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}