#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
set <int> neigh[Maxn];
int dp[Maxn][2];
vector <int> sav[Maxn][2], simpl[Maxn][2];
vector <ii> A, B;
bool tk[Maxn];

int Get(int v, int p)
{
	set <int> tmp = neigh[v]; neigh[v].clear();
	tk[v] = true;
	if (*(tmp.begin()) == p)
		tmp.erase(tmp.begin());
	if (tmp.empty()) return v;
	return Get(*(tmp.begin()), v);
}

void Solve(int v, int p)
{
	dp[v][0] = dp[v][1] = 0;
	sav[v][0].clear(); sav[v][1].clear();
	simpl[v][0].clear(); simpl[v][1].clear();
	vector <ii> seq;
	for (auto u: neigh[v]) {
		if (u == p) continue;
		Solve(u, v);
		dp[v][0] += dp[u][0];
		dp[v][1] += dp[u][0];
		seq.push_back(ii(1 + dp[u][1] - dp[u][0], u));
	}
	sort(seq.begin(), seq.end());
	int tk0 = max(0, int(neigh[v].size()) - 2);
	for (int i = 0; i < tk0; i++) {
		dp[v][0] += seq[i].first;
		sav[v][0].push_back(seq[i].second);
	}
	for (int i = tk0; i < seq.size(); i++)
		simpl[v][0].push_back(seq[i].second);
	int tk1 = max(0, int(neigh[v].size()) - 3);
	for (int i = 0; i < tk1; i++) {
		dp[v][1] += seq[i].first;
		sav[v][1].push_back(seq[i].second);
	}
	for (int i = tk1; i < seq.size(); i++)
		simpl[v][1].push_back(seq[i].second);
}

void Gen(int v, int wh)
{
	for (int i = 0; i < sav[v][wh].size(); i++) {
		int u = sav[v][wh][i];
		neigh[v].erase(u);
		neigh[u].erase(v);
		A.push_back(ii(v, u));
		Gen(u, 1);
	}
	for (int i = 0; i < simpl[v][wh].size(); i++) {
		int u = simpl[v][wh][i];
		Gen(u, 0);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			tk[i] = false;
		}
		A.clear(); B.clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].insert(b);
			neigh[b].insert(a);
		}
		Solve(1, 0);
		Gen(1, 0);
		int lst = 0;
		for (int i = 1; i <= n; i++) if (neigh[i].size() == 1) {
			int got = Get(i, 0);
			if (lst) B.push_back(ii(lst, i));
			lst = got;
		} else if (neigh[i].size() == 0 && !tk[i]) {
			if (lst) B.push_back(ii(lst, i));
			lst = i;
		}
		assert(A.size() == B.size());
		printf("%d\n", int(A.size()));
		for (int i = 0; i < A.size(); i++)
			printf("%d %d %d %d\n", A[i].first, A[i].second, B[i].first, B[i].second);
	}
    return 0;
}