#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ok=0;
        for(i=1;i<=n;++i)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(b==c)
                ok=1;
        }
        if(m%2)
            ok=0;
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}