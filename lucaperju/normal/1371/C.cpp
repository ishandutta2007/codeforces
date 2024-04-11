#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>m;
        if(a+b<n+m)
        {
            cout<<"No\n";
            continue;
        }
        if(min(a,b)>=m)
            cout<<"YES\n";
        else
            cout<<"No\n";
    }
    return 0;
}