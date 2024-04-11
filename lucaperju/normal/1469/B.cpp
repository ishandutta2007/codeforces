#include <bits/stdc++.h>
using namespace std;
char v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sc=0,mx1=0,mx2=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            sc+=a;
            mx1=max(mx1,sc);
        }
        cin>>m;
        sc=0;
        for(i=1;i<=m;++i)
        {
            long long a;
            cin>>a;
            sc+=a;
            mx2=max(mx2,sc);
        }
        cout<<mx1+mx2<<'\n';
    }
    return 0;
}