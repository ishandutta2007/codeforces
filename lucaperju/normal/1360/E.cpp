#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                char c;
                cin>>c;
                v[i][j]=c-'0';
            }
        int ok=1;
        for(i=1;i<n;++i)
            for(j=1;j<n;++j)
            {
                if(v[i][j]==1 && v[i+1][j]+v[i][j+1]==0)
                    ok=0;
            }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}