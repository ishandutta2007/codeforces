#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 100005;

int n;
int f[Maxn], s[Maxn];
vector <int> neigh[Maxn];
bool taken[Maxn];
vector <int> comp;
int root, mid;
ii edge;
ii dp[Maxn][2];
int from[Maxn];
ii res = ii(0, 0);
vector <ii> rpairs;

ii Max(ii a, ii b) 
{ 
	if (a.first != b.first) return a.first > b.first? a: b;
	return a.second > b.second? a: b;
}

ii Add(ii a, ii b) { return ii(a.first + b.first, a.second + b.second); }

ii Sub(ii a, ii b) { return ii(a.first - b.first, a.second - b.second); }

void getComp(int v)
{
	comp.push_back(v); taken[v] = true;
	while (!taken[f[v]]) { v = f[v]; comp.push_back(v); taken[v] = true; }
	root = v; mid = f[v]; edge = ii(1, s[root] != s[mid]);
	for (int i = 0; i < comp.size(); i++) {
		int v = comp[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (!taken[u]) { comp.push_back(u); taken[u] = true; }
		}
	}
}

void Calc(int v)
{
	taken[v] = true;
	dp[v][0] = dp[v][1] = ii(0, 0);
	ii mx = ii(-Inf, -Inf);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (taken[u]) continue;
		Calc(u);
		dp[v][0] = Add(dp[v][0], Max(dp[u][0], dp[u][1]));
		mx = Max(mx, Add(ii(1, s[v] != s[u]), Sub(dp[u][0], Max(dp[u][0], dp[u][1]))));
	}
	dp[v][1] = Add(dp[v][0], mx);
}

void Get(int v, int f)
{
	taken[v] = true;
	int spec;
	if (f == 0) spec = -1;
	else {
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (taken[u]) continue;
			if (Sub(dp[v][1], dp[v][0]) == Add(ii(1, s[v] != s[u]), Sub(dp[u][0], Max(dp[u][0], dp[u][1])))) {
				spec = u; break;
			}
		}
		rpairs.push_back(ii(v, spec));
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (taken[u]) continue;
		if (spec == u) Get(u, 0);
		else if (Max(dp[u][0], dp[u][1]) != dp[u][0]) Get(u, 1);
			 else Get(u, 0);
	}
}

void Process(int i)
{
	comp.clear(); getComp(i);
	for (int i = 0; i < comp.size(); i++) taken[comp[i]] = false;
	Calc(root);
	ii a = Max(dp[root][0], dp[root][1]);
	for (int i = 0; i < comp.size(); i++) taken[comp[i]] = false;
	taken[root] = taken[mid] = true; Calc(root); Calc(mid);
	ii b = Add(edge, Add(dp[root][0], dp[mid][0]));
	if (Max(a, b) != b) {
		for (int i = 0; i < comp.size(); i++) taken[comp[i]] = false;
		Calc(root);
		for (int i = 0; i < comp.size(); i++) taken[comp[i]] = false;
		if (Max(dp[root][0], dp[root][1]) != dp[root][0]) Get(root, 1);
		else Get(root, 0);
	} else { 
		for (int i = 0; i < comp.size(); i++) taken[comp[i]] = false;
		taken[root] = taken[mid] = true;
		rpairs.push_back(ii(root, mid)); Get(root, 0); Get(mid, 0); 
	}
	res = Add(res, Max(a, b));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &f[i], &s[i]);
		neigh[f[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (neigh[i].empty() && !taken[i])
		Process(i);
	for (int i = 1; i <= n; i++) if (!taken[i])
		Process(i);
	printf("%d %d\n", res.first, res.second);
	for (int i = 0; i < rpairs.size(); i++)
		printf("%d %d\n", rpairs[i].first, rpairs[i].second);
	return 0;
}