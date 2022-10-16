#include <bits/stdc++.h>

using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=n;i>=1;--i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
    return 0;
}