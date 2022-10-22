#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxl = 1000005;

char str[Maxl];
int n;
int wh[Maxn][Maxn];
vector <vector <int> > V[Maxn], rV[Maxn];
int L[Maxn][Maxn], cnt[Maxn], lst[Maxn][Maxn];
bool tk[Maxn];
vector <ii> res;
vector <int> neigh[Maxn];
vector <int> tmp;

void Collect(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	tmp.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!tk[u]) Collect(u);
	}
}

bool Check()
{
	for (int i = 1; i <= n; i++) {
		fill(tk, tk + n + 1, false); tk[i] = true;
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			if (tk[u]) return false;
			tmp.clear(); Collect(u);
			sort(tmp.begin(), tmp.end());
			rV[i].push_back(tmp);
		}
		sort(rV[i].begin(), rV[i].end());
		if (rV[i] != V[i]) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		string s = str;
		for (int j = 0; j < s.length(); j++)
			if (s[j] == '-') s[j] = ' ';
		stringstream ss(s);
		while (ss >> s) {
			vector <int> cur;
			for (int j = 0; j < s.length(); j++)
				if (s[j] == ':' || s[j] == ',') s[j] = ' ';
			stringstream ss2(s);
			int sz; ss2 >> sz; cur.resize(sz);
			for (int j = 0; j < sz; j++)
				ss2 >> cur[j];
			sort(cur.begin(), cur.end());
			V[i].push_back(cur);
		}
		for (int j = 0; j < V[i].size(); j++) {
			L[i][j] = V[i][j].size();
			for (int k = 0; k < V[i][j].size(); k++)
				wh[V[i][j][k]][i] = j;
		}
		sort(V[i].begin(), V[i].end());
		cnt[i] = V[i].size();
	}
	vector <int> seq;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 1) seq.push_back(i);
	for (int i = 0; i < seq.size(); i++) {
		int v = seq[i];
		for (int j = 0; j < V[v].size(); j++) {
			if (L[v][j] == 0) {
				res.push_back(ii(v, lst[v][j]));
				neigh[v].push_back(lst[v][j]);
				neigh[lst[v][j]].push_back(v);
			}
		}
		for (int j = 1; j <= n; j++) if (v != j) {
			if (cnt[j] == 2 && L[j][wh[v][j]] == 1) {
				seq.push_back(j);
			}
			lst[j][wh[v][j]] = v;
			if (--L[j][wh[v][j]] == 0) cnt[j]--;
		}
	}
	if (seq.size() < n || res.size() != n - 1 || !Check()) { printf("-1\n"); return 0; }
	printf("%d\n", n - 1);
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}