#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n, m;
vector <iii> E;
set <ii> S;
int par[Maxn];
vector <int> V[Maxn];
set <int> P;
ll res;

bool hasEdge(int a, int b)
{
	return S.find(ii(min(a, b), max(a, b))) != S.end();
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b, bool nzer = false)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (V[a].size() < V[b].size()) swap(a, b);
	for (int i = 0; i < V[b].size(); i++)
		V[a].push_back(V[b][i]);
	V[b].clear();
	par[b] = a;
	P.erase(b);
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		V[i].push_back(i);
	}
	int lst = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		E.push_back(iii(c, ii(a, b)));
		S.insert(ii(min(a, b), max(a, b)));
		lst ^= c;
	}
	vector <iii> relE;
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++)
		if (unionSet(E[i].second.first, E[i].second.second))
			relE.push_back(E[i]);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		V[i].clear();
		V[i].push_back(i);
	}
	bool spec = true;
	for (int i = 1; i <= n; i++) {
		auto cop = P;
		P.insert(i);
		for (auto v: cop) {
			int cnt = 0;
			for (int j = 0; j < V[v].size() && cnt < 2; j++)
				cnt += !hasEdge(i, V[v][j]);
			if (cnt == 2) spec = false;
			if (cnt > 0) unionSet(v, i);
		}
	}
	ll mn = Inf;
	for (int i = 0; i < relE.size(); i++)
		if (getPar(relE[i].second.first) == getPar(relE[i].second.second))
			mn = min(mn, ll(relE[i].first));
		else if (unionSet(relE[i].second.first, relE[i].second.second))
			res += relE[i].first;
	if (spec) res += min(mn, ll(lst));
	cout << res << endl;
    return 0;
}