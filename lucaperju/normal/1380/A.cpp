#include <bits/stdc++.h>
using namespace std;
int v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<n-1;++i)
        {
            if(v[i]<v[i+1]&&v[i+2]<v[i+1])
                  break;
        }
        if(i==n-1)
            cout<<"NO\n";
        else
            cout<<"YES\n"<<i<<' '<<i+1<<' '<<i+2<<'\n';
    }
    return 0;
}