#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int ind[Maxn];
vector <int> seq;
int n;
vector <int> neigh[Maxn];
bool er[Maxn];
int cnt[Maxn];

void Count(int v, int p)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		Count(u, v);
		cnt[v] += cnt[u];
	}
}

bool Solve(int v);

void Traverse(int v, int p, int small, int big, vector <int> &good, int &from)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		Traverse(u, v, small, big, good, from);
		if (cnt[u] == small) {
			er[v] = true;
			if (Solve(u)) {
				good.push_back(u);
				from = v;
			}
			er[v] = false;
		}
		if (cnt[u] == big) {
			er[u] = true;
			if (Solve(v)) {
				good.push_back(v);
				from = u;
			}
			er[u] = false;
		}
	}
}

bool Solve(int v)
{
	Count(v, 0);
	if (cnt[v] <= 3) return true;
	int my = ind[cnt[v]];
	vector <int> good;
	int from;
	Traverse(v, 0, seq[my - 2], seq[my - 1], good, from);
	if (good.empty()) return false;
	if (good.size() == 1) {
		er[good[0]] = true;
		bool res = Solve(from);
		er[good[0]] = false;
		return res;
	}
	if (good.size() == 2) {
		er[good[0]] = er[good[1]] = true;
		bool res = Solve(from);
		er[good[0]] = er[good[1]] = false;
		return res;
	}
	assert(false);
}

int main()
{
	seq.push_back(0);
	seq.push_back(1);
	while (seq[int(seq.size()) - 2] + seq.back() < Maxn) {
		int nw = seq[int(seq.size()) - 2] + seq.back();
		ind[nw] = seq.size();
		seq.push_back(nw);
	}
	scanf("%d", &n);
	if (!ind[n]) { printf("NO\n"); return 0; }
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	printf("%s\n", Solve(1)? "YES": "NO");
    return 0;
}