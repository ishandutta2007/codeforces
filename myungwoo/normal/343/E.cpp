#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

int N,M,ans;
int earn[202][202],w[202][202],mem[202][202];
int dist[202],cnt[203];
vector <int> con[202],order,path;
bool vis[202];

void bfs()
{
    int i,k,q;
    queue <int> que;
    for (i=0;i<=N+1;i++) dist[i] = N+2;
    for (i=0;i<=N+2;i++) cnt[i] = 0;
    dist[N+1] = 0, que.push(N+1);
    while (!que.empty()){
        q = que.front(); que.pop();
        for (i=sz(con[q]);i--;){
            k = con[q][i];
            if (w[k][q] && dist[k] == N+2) dist[k] = dist[q]+1, que.push(k);
        }
    }
    for (i=0;i<=N+1;i++) cnt[dist[i]]++;
}

int dfs(int n)
{
    int i,k,ret;
    path.pb(n);
    if (n == N+1) return 1;
    for (i=sz(con[n]);i--;){
        k = con[n][i];
        if (w[n][k] && dist[k]+1 == dist[n] && (ret = dfs(k))) return ret;
    }
    int tmp = dist[n];
    dist[n] = N+2;
    for (i=sz(con[n]);i--;){
        k = con[n][i];
        if (w[n][k] && dist[n] > dist[k]+1) dist[n] = dist[k]+1;
    }
    cnt[dist[n]]++;
    if (!--cnt[tmp]) return -1;
    return 0;
}

int max_flow(int source,int sink)
{
    memcpy(w,mem,sizeof(w));
    w[0][source] = 1e9;
    w[sink][N+1] = 1e9;
    bfs();
    int ret=0;
    while (dist[0] < N+2){
        path.clear();
        int val = dfs(0);
        if (val < 0) break;
        if (!val) continue;
        int flow=2e9,i;
        for (i=1;i<sz(path);i++) put_min(flow,w[path[i-1]][path[i]]);
        for (i=1;i<sz(path);i++) w[path[i-1]][path[i]] -= flow, w[path[i]][path[i-1]] += flow;
        ret += flow;
    }
    return ret;
}

inline void addEdge(int s,int e,int f)
{
    if (!w[s][e]) w[s][e] = w[e][s] = f, con[s].pb(e), con[e].pb(s);
}

int main()
{
    int i,j,k,v;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&v);
        addEdge(j,k,v);
    }
    memcpy(mem,w,sizeof(w));
    for (i=1;i<=N;i++) con[0].pb(i), con[i].pb(0), con[i].pb(N+1), con[N+1].pb(i);
    for (i=1;i<=N;i++) for (j=i+1;j<=N;j++){
        earn[i][j] = earn[j][i] = max_flow(i,j);
    }
    order.push_back(1); vis[1] = 1;
    while (sz(order) < N){
        int n = order.back();
        int mx = -2e9, tar = 0;
        for (i=1;i<=N;i++) if (!vis[i] && mx < earn[n][i]) mx = earn[n][i], tar = i;
        order.pb(tar); vis[tar] = 1;
        ans += earn[n][tar];
    }
    printf("%d\n",ans);
    for (i=0;i<sz(order);i++) printf("%d ",order[i]); puts("");
}