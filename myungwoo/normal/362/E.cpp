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

#pragma comment(linker,"/STACK:33554432")

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

int N,K,ans;
int w[51][51],o[51][51];
int dist[51],from[51];
bool vis[51];

vector <int> path;
priority_queue <pii> que;

bool dfs(int n)
{
	int i;
	path.pb(n); vis[n] = 1;
	if (n == N) return 1;
	for (i=1;i<=N;i++) if (!vis[i] && w[n][i] && dfs(i)) return 1;
	path.pop_back();
	return 0;
}

int main()
{
	int i,j;
	scanf("%d%d",&N,&K);
	for (i=1;i<=N;i++) for (j=1;j<=N;j++){
		scanf("%d",w[i]+j); o[i][j] = w[i][j];
	}
	while (dfs(1)){
		int flow=2e9;
		for (i=1;i<sz(path);i++) put_min(flow,w[path[i-1]][path[i]]);
		for (i=1;i<sz(path);i++) w[path[i-1]][path[i]] -= flow, w[path[i]][path[i-1]] += flow;
		set(vis,0);
		path.clear();
		ans += flow;
	}
	while (K--){
		while (!que.empty()) que.pop();
		for (i=1;i<=N;i++) dist[i] = 1e9;
		dist[1] = 0; que.push(mp(0,1));
		while (!que.empty()){
			int d = -que.top().fr;
			int q = que.top().sc; que.pop();
			if (dist[q] != d) continue;
			for (i=1;i<=N;i++) if (o[q][i]){
				if (dist[i] > dist[q]+!w[q][i])
					dist[i] = dist[q]+!w[q][i],
					que.push(mp(-dist[i],i)), from[i] = q;
			}
		}
		if (dist[N] == 1e9) break;
		for (i=N;i>1;){
			j = from[i];
			if (!w[j][i]){ w[j][i]++; break; }
			i = j;
		}
		path.clear(); set(vis,0);
		if (dfs(1)){
			for (i=1;i<sz(path);i++) w[path[i-1]][path[i]]--, w[path[i]][path[i-1]]++;
			ans++;
		}
	}
	printf("%d\n",ans);
}