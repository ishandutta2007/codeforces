#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>e[200001];
bool vis[200001];
int ans=0;
int dfs(int now)
{
    vis[now]=true;
    int an=0,bo=0;
    for(auto x:e[now])
    if(vis[x]==false)
    {
        int qwq=dfs(x);
        if(qwq==0)an++,bo=1;
    }
    if(now!=1)ans+=max(an-1,0ll);
    else ans+=an;
    if(now==1&&bo==0&&an==0)ans++;
    return bo;
}
main()
{
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        for(int x=1;x<=n;x++)
        e[x].clear(),vis[x]=false;
        for(int x=1;x<n;x++)
        {
            int y,z;
            cin>>y>>z;
            e[y].push_back(z);
            e[z].push_back(y);
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
}