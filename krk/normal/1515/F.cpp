#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 300005;

int n, m, x;
int A[Maxn], B[Maxn];
int has[Maxn];
int par[Maxn], siz[Maxn];
ll dp[Maxn];
vector <ii> neigh[Maxn];
vector <int> res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	return true;
}

void Traverse(int v, int p)
{
	dp[v] = has[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == p) continue;
		Traverse(u, v);
		dp[v] += dp[u] - x;
	}
}

void Solve(int v, int p)
{
	vector <llii> seq;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == p) continue;
		seq.push_back(llii(dp[u], neigh[v][i]));
	}
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i < seq.size(); i++)
		if (seq[i].first >= 0) {
			Solve(seq[i].second.first, v);
			res.push_back(seq[i].second.second);
		}
		else {
			res.push_back(seq[i].second.second);
			Solve(seq[i].second.first, v);
		}
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &has[i]);
		par[i] = i; siz[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (unionSet(a, b)) {
			neigh[a].push_back(ii(b, i));
			neigh[b].push_back(ii(a, i));
		}
	}
	Traverse(1, 0);
	if (dp[1] < 0) { printf("NO\n"); return 0; }
	Solve(1, 0);
	printf("YES\n");
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
    return 0;
}