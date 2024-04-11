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
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m, k;
int r[Maxn];
vector <int> neigh[Maxn], rneigh[Maxn];
int in[Maxn], out[Maxn];
set <int> S;
int mn[Maxn], mx[Maxn];
vector <int> add[Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		S.insert(i);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
		if (r[i] > 0) { S.erase(r[i]); mn[i] = r[i]; mx[i] = r[i]; }
		else mn[i] = 1, mx[i] = k;
	}
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		rneigh[b].push_back(a);
		out[a]++; in[b]++;
	}
	vector <int> seq;
	for (int i = 1; i <= n; i++)
		if (out[i] == 0) seq.push_back(i);
	for (int i = 0; i < seq.size(); i++) {
		int v = seq[i];
		if (r[v] > 0 && mn[v] > r[v]) { printf("-1\n"); return 0; }
		for (int j = 0; j < rneigh[v].size(); j++) {
			int u = rneigh[v][j];
			mn[u] = max(mn[u], mn[v] + 1);
			if (--out[u] == 0) seq.push_back(u);
		}
	}
	if (seq.size() < n) { printf("-1\n"); return 0; }
	seq.clear();
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) seq.push_back(i);
	for (int i = 0; i < seq.size(); i++) {
		int v = seq[i];
		if (r[v] > 0 && mx[v] < r[v]) { printf("-1\n"); return 0; }
		if (mx[v] < mn[v]) { printf("-1\n"); return 0; }
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			mx[u] = min(mx[u], mx[v] - 1);
			if (--in[u] == 0) seq.push_back(u); 
		}
	}
	if (seq.size() < n) { printf("-1\n"); return 0; }
	for (int i = 1; i <= n; i++)
		add[mx[i]].push_back(i);
	priority_queue <ii> Q;
	for (int i = k; i > 0; i--) {
		for (int j = 0; j < add[i].size(); j++) {
			int ind = add[i][j];
			Q.push(ii(mn[ind], ind));
		}
		if (S.find(i) != S.end()) {
			while (!Q.empty() && Q.top().first > i) {
				ii v = Q.top(); Q.pop();
				r[v.second] = v.first;
			}
			if (Q.empty()) { printf("-1\n"); return 0; }
			ii v = Q.top(); Q.pop();
			r[v.second] = i;
		}
	}
	while (!Q.empty()) {
		ii v = Q.top(); Q.pop();
		r[v.second] = v.first;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", r[i], i + 1 <= n? ' ': '\n');
	return 0;
}