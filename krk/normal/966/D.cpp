#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Inf = 1000000000;

int n, m;
set <int> S[Maxn];
int dist[Maxn], par[Maxn];
int res1 = Inf;
vector <int> seq1;
bool tk[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		S[a].insert(b);
		S[b].insert(a);
	}
	fill(dist, dist + n + 1, Inf); dist[1] = 0;
	queue <int> Q; Q.push(1);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (set <int>::iterator it = S[v].begin(); it != S[v].end(); it++) {
			int u = *it;
			if (dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1; par[u] = v;
				Q.push(u);
			}
		}
	}
	res1 = dist[n];
	if (res1 < Inf) {
		int v = n;
		while (v) {
			seq1.push_back(v);
			v = par[v];
		}
	}
	if (res1 > 4) {
		bool found = false;
		for (set <int>::iterator it = S[1].begin(); it != S[1].end() && !found; it++) {
			int u = *it;
			for (set <int>::iterator it2 = S[u].begin(); it2 != S[u].end() && !found; it2++)
				if (*it2 != 1 && S[1].find(*it2) == S[1].end()) {
					found = true;
					res1 = 4;
					seq1.clear();
					seq1.push_back(n);
					seq1.push_back(1);
					seq1.push_back(*it2);
					seq1.push_back(u);
					seq1.push_back(1);
				}
		}
	}
	if (res1 > 5) {
		bool found = false;
		for (set <int>::iterator it = S[1].begin(); it != S[1].end() & !found; it++) {
			int u = *it;
			if (tk[u]) continue;
			tk[u] = true;
			for (set <int>::iterator it2 = S[u].begin(); it2 != S[u].end() && !found; it2++) if (*it2 != 1) {
				int z = *it2; tk[z] = true;
				set <int>::iterator lef = S[u].begin();
				set <int>::iterator rig = S[z].begin();
				while ((lef != S[u].end() || rig != S[z].end()) && !found) {
					if (lef != S[u].end() && *lef == z) { lef++; continue; }
					if (rig != S[z].end() && *rig == u) { rig++; continue; }
					if (lef != S[u].end() && rig != S[z].end() && *lef == *rig) { lef++; rig++; continue; }
					int a, b, c;
					if (rig == S[z].end() || lef != S[u].end() && *lef < *rig) { a = z; b = u; c = *lef; }
					else { a = u; b = z; c = *rig; }
					found = true;
					res1 = 5;
					seq1.clear();
					seq1.push_back(n);
					seq1.push_back(a);
					seq1.push_back(c);
					seq1.push_back(b);
					seq1.push_back(a);
					seq1.push_back(1);
				}
			}
		}
	}
	if (res1 >= Inf) printf("-1\n");
	else {
		printf("%d\n", res1);
		for (int i = int(seq1.size()) - 1; i >= 0; i--)
			printf("%d%c", seq1[i], i - 1 >= 0? ' ': '\n');
	}
	return 0;
}