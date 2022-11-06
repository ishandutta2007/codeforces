#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001000]; 
int n, k, d[1010000], ans = 0;
int h[1010000], nxt[2010000], to[2010000], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int dfs(int x, int fa)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		v[x].push_back(dfs(to[i], x));
	}
	if(v[x].size() == 0) return 1;
	sort(v[x].begin(), v[x].end());
	int S = v[x].size();
	int i;
	for(i = 1; i < S; i++)
	{ 
		if(v[x][i] + v[x][i - 1] > k) break;
	}
	ans += S - i; 
	return v[x][i - 1] + 1;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u); d[u]++; d[v]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(d[i] >= 2) {dfs(i, 0); ans++; printf("%d\n", ans); return 0;}
	}
}