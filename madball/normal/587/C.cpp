#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 1e+9 + 7;
const int lim = 100500;
const int limln = 20;
const int maxq = 10;

void ins(int *ar, int val) {
	int i;
	for (i = maxq - 1; i >= 0; --i)
		if (ar[i] && (ar[i] < val)) {
			if (i < maxq - 1)
				ar[i + 1] = val;
			break;
		}
		else
			if (i < maxq - 1)
				ar[i + 1] = ar[i];
	if (i == -1)
		ar[0] = val;
}

void mer(int *ar1, int *ar2, int *target) {
	int l = 0, r = 0;
	for (int i = 0; i < maxq; ++i)
		if ((l == maxq) || (r != maxq) && ar2[r] && ((ar2[r] < ar1[l]) || !ar1[l]))
			target[i] = ar2[r++];
		else
			target[i] = ar1[l++];
}

int ta[maxq];
void mer_add(int *ar1, int *ar2) {
	for (int i = 0; i < maxq; ++i)
		ta[i] = 0;
	mer(ar1, ar2, ta);
	for (int i = 0; i < maxq; ++i)
		ar1[i] = ta[i];
}

vector<int> graph[lim];
int par[lim];
int lvl[lim];
int risev[limln][lim];
int rise[limln][lim][maxq];
int people[lim][maxq];

int cur[maxq];

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); ++i)
		if (!lvl[graph[v][i]]) {
			lvl[graph[v][i]] = lvl[v] + 1;
			par[graph[v][i]] = v;
			dfs(graph[v][i]);
		}
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q, i, j, a, b, k;
	cin >> n >> m >> q;
	for (i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (i = 0; i < m; ++i) {
		cin >> a;
		ins(people[a - 1], i + 1);
	}

	lvl[0] = 1;
	par[0] = 0;
	dfs(0);

	int llen, len;
	for (llen = 0, len = 1; len < n; ++llen, len <<= 1) {
		for (i = 0; i < n; ++i)
			if (lvl[i] > len) {
				if (llen) {
					risev[llen][i] = risev[llen - 1][risev[llen - 1][i]];
					mer(rise[llen - 1][i], rise[llen - 1][risev[llen - 1][i]], rise[llen][i]);
				}
				else {
					for (j = 0; j < maxq; ++j)
						rise[0][i][j] = people[i][j];
					risev[0][i] = par[i];
				}
			}
	}

	int x, y, z;
	for (i = 0; i < q; ++i) {
		cin >> a >> b >> k;
		--a;
		--b;
		for (j = 0; j < maxq; ++j)
			cur[j] = 0;
		if (lvl[a] < lvl[b])
			swap(a, b);
		for (x = 1, y = 0; x <= lvl[a] - lvl[b]; x <<= 1, ++y)
			if (x & (lvl[a] - lvl[b])) {
				mer_add(cur, rise[y][a]);
				a = risev[y][a];
			}
		for (y = 0; risev[y][a] != risev[y][b]; ++y);
		for (; y >= 0; --y)
			if (risev[y][a] != risev[y][b]) {
				mer_add(cur, rise[y][a]);
				a = risev[y][a];
				mer_add(cur, rise[y][b]);
				b = risev[y][b];
			}
		if (a != b) {
			mer_add(cur, rise[0][a]);
			mer_add(cur, rise[0][b]);
			mer_add(cur, people[risev[0][a]]);
		}
		else
			mer_add(cur, people[a]);
		for (j = 0; j < k; ++j)
			if (!cur[j])
				break;
		cout << j;
		for (k = 0; k < j; ++k)
			cout << ' ' << cur[k];
		cout << '\n';
	}
	return 0;
}