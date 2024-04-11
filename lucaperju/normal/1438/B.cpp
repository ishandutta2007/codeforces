#include <bits/stdc++.h>
using namespace std;
int v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,i,m,j,mx=0,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int ok=0;
        for(i=1;i<n;++i)
        {
            if(v[i]==v[i+1])
                ok=1;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}