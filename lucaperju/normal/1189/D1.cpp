#include <bits/stdc++.h>

using namespace std;
vector <int> v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j,sc=0;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ok=1;
    for(i=1;i<=n;++i)
    {
        if(v[i].size()==2)
            ok=0;
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}