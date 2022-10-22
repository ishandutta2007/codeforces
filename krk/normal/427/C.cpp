#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n;
int C[Maxn];
int m;
vector <int> neigh[Maxn];
int cur, num[Maxn], low[Maxn];
bool tk[Maxn];
vector <int> S;
ll res, ways = 1;

void SCC(int v)
{
	num[v] = low[v] = ++cur;
	S.push_back(v); tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!num[u]) SCC(u);
		if (tk[u]) low[v] = min(low[v], low[u]);
	}
	if (num[v] == low[v]) {
		int mn = mod, cnt = 0;
		while (true) {
			int u = S.back(); S.pop_back(); tk[u] = false;
			if (C[u] < mn) { mn = C[u]; cnt = 0; }
			if (C[u] == mn) cnt++;
			if (u == v) break; 
		}
		res += mn; ways = ways * cnt % mod;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &C[i]);
	scanf("%d", &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (!num[i]) SCC(i);
	printf("%I64d %I64d\n", res, ways);
	return 0;
}