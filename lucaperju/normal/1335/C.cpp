#include <bits/stdc++.h>
using namespace std;
int v[200005],fv[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j=0,n,t,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            ++fv[v[i]];
            mx=max(mx,fv[v[i]]);
            if(fv[v[i]]==1)
                ++cnt;
        }
        if(cnt==mx)
            cout<<cnt-1<<'\n';
        else
            cout<<min(cnt,mx)<<'\n';
        for(i=1;i<=n;++i)
            fv[v[i]]=0;
    }
    return 0;
}