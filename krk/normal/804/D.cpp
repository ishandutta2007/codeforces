#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;
typedef long double ld;

const int Maxn = 100005;
const int Maxp = 320;
const int Maxq = 320;

int n, m, q;
vector <int> neigh[Maxn];
int cur, col[Maxn];
int best[Maxn][2];
vector <int> dist[Maxn];
vector <ll> sum[Maxn];
int bcur, mybig[Maxn];
int ibig[Maxq];
llll res[Maxq][Maxq];

void insertBest(int best[], int x)
{
	if (x > best[0]) best[1] = best[0], best[0] = x;
	else if (x > best[1]) best[1] = x;
}

int getBest(int best[], int x)
{
	return best[0] == x? best[1]: best[0];
}

void Traverse1(int v, int c, int p = 0)
{
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, c, v);
		insertBest(best[v], best[u][0] + 1);
	}
}

void Traverse2(int v, int p, int tp)
{
	dist[col[v]].push_back(max(best[v][0], tp));
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse2(u, v, max(tp, getBest(best[v], best[u][0] + 1)) + 1);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!col[i]) {
		cur++; Traverse1(i, cur);
		Traverse2(i, 0, 0);
		sort(dist[cur].begin(), dist[cur].end());
		sum[cur].resize(dist[cur].size());
		sum[cur].back() = dist[cur].back();
		for (int j = int(sum[cur].size()) - 2; j >= 0; j--)
			sum[cur][j] = sum[cur][j + 1] + dist[cur][j];
		if (dist[cur].size() > Maxp) { mybig[cur] = ++bcur; ibig[bcur] = cur; }
	}
	for (int i = 1; i <= bcur; i++)
		for (int j = 1; j <= bcur; j++) {
			int v = ibig[i], u = ibig[j];
			if (dist[v].back() < dist[u].back() || i == j) continue;
			for (int k = 0; k < dist[v].size(); k++) {
				int ind = upper_bound(dist[u].begin(), dist[u].end(), dist[v].back() - dist[v][k] - 1) - dist[u].begin();
				if (ind < dist[u].size()) {
					res[i][j].first += dist[u].size() - ind;
					res[i][j].second += ll(dist[u].size() - ind) * ll(dist[v][k] + 1) + sum[u][ind];
				}
			}
		}
	for (int i = 0; i < q; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (col[a] == col[b]) printf("-1\n");
		else {
			int v = col[a], u = col[b];
			if (dist[v].size() > dist[u].size()) swap(v, u);
			llll myres = llll(0, 0);
			int diam = max(dist[v].back(), dist[u].back());
			if (dist[v].size() <= Maxp) {
				for (int k = 0; k < dist[v].size(); k++) {
					int ind = upper_bound(dist[u].begin(), dist[u].end(), diam - dist[v][k] - 1) - dist[u].begin();
					if (ind < dist[u].size()) {
						myres.first += dist[u].size() - ind;
						myres.second += ll(dist[u].size() - ind) * ll(dist[v][k] + 1) + sum[u][ind];
					}
				}
			} else if (dist[v].back() == diam) myres = res[mybig[v]][mybig[u]];
				   else myres = res[mybig[u]][mybig[v]];
			ll tot = ll(dist[v].size()) * dist[u].size();
			ll lft = tot - myres.first;
			ld pr = ld(myres.second + ll(diam) * lft) / ld(tot);
			printf("%.12lf\n", double(pr));
		}
	}
	return 0;
}