#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(a*n!=b*m)
        {
            cout<<"NO\n";
            continue;
        }
        int pz=1;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                v[i][j]=0;
        for(i=1;i<=n;++i)
        {
            for(j=pz;j<=pz+a-1;++j)
                v[i][(j-1)%m+1]=1;
            pz=j;
        }
        cout<<"YES\n";
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j];
            cout<<'\n';
        }
    }
    return 0;
}