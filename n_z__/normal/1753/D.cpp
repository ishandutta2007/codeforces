// LUOGU_RID: 91296951
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<string>s(n+2);
    for(int x=1;x<=n;x++)
    cin>>s[x],s[x]='#'+s[x]+'#';
    for(int x=0;x<=m+1;x++)
    s[0].push_back('#'),s[n+1].push_back('#');
    auto hsh=[&](int x,int y){return x*(m+5)+y;};
    auto unhsh=[&](int x)->pair<int,int>{return {x/(m+5),x%(m+5)};};
    vector<int>f(hsh(n+5,m+5)+1),vis(hsh(n+5,m+5)+1);
    for(int x=1;x<=n;x++)
    for(int y=1;y<=m;y++)
    f[hsh(x,y)]=1e18;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int x=1;x<=n;x++)
    for(int y=1;y<=m;y++)
    if(s[x][y]=='.')pq.push({0,hsh(x,y)});
    int ans=1e18;
    while(!pq.empty())
    {
        int w=pq.top().first;
        auto [u,v]=unhsh(pq.top().second);
        pq.pop();
        if(vis[hsh(u,v)])continue;
        vis[hsh(u,v)]=1;
        f[hsh(u,v)]=w;
        for(int k=0;k<4;k++)
        {
            int ddx=u+dx[k],ddy=v+dy[k];
            if(s[ddx][ddy]=='D')ddx--;
            else if(s[ddx][ddy]=='U')ddx++;
            else if(s[ddx][ddy]=='R')ddy--;
            else if(s[ddx][ddy]=='L')ddy++;
            else continue;
            if(vis[hsh(ddx,ddy)])continue;
            if(ddx!=u&&ddy!=v)pq.push({w+p,hsh(ddx,ddy)});
            else pq.push({w+q,hsh(ddx,ddy)});
        }
    }
    for(int x=1;x<=n;x++)
    for(int y=1;y<=m;y++)
    {
        if(y<m)ans=min(ans,f[hsh(x,y)]+f[hsh(x,y+1)]);
        if(x<n)ans=min(ans,f[hsh(x,y)]+f[hsh(x+1,y)]);
    }
    if(ans<1e18)cout<<ans<<endl;
    else cout<<-1<<endl;
}