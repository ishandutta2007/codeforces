#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j,sc=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    if(v[n]>=v[n-1]+v[n-2])
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(i=n;i>=1;i-=2)
        cout<<v[i]<<' ';
    i+=2;
    i=3-i;
    for(;i<=n;i+=2)
        cout<<v[i]<<' ';
    return 0;
}