#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
ll N,M,W[MN],u,v,s,vis[MN],ch[MN],sum[MN],ans,bonus;
vector<int> G[MN];

bool dfs(int cur, int par)
{
    bool iscy = false;
    vis[cur] = 1;
    for(int next : G[cur]){
        if(next==par) continue;
        if(vis[next]) iscy = true;
        else if(dfs(next,cur)) iscy = true;
    }
    return ch[cur] = iscy;
}

void DFS(int cur, int par, ll res)
{
    bool isleaf = true;
    vis[cur] = 1;
    if(ch[cur]) res = sum[cur];
    for(int next : G[cur]){
        if(next==par || vis[next]) continue;
        sum[next] = sum[cur] + W[next];
        DFS(next,cur,res);
        isleaf = false;
    }
    if(isleaf){
        //cout << cur << ' ' << sum[cur] << ' ' << res << '\n';
        bonus = max(bonus,sum[cur]-res);
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> W[i];
    }
    for(int i=0; i<M; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> s;
    dfs(s,s);
    fill(vis,vis+N+1,0);
    DFS(s,s,0);
    for(int i=1; i<=N; i++){
        if(ch[i] || i==s) ans += W[i];
    }
    ans += bonus;
    cout << ans;
}