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
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        cout<<(v[b]-v[a-1])/10<<'\n';
    }
    return 0;
}