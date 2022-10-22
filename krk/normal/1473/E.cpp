#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 2;
const ll Inf = 1000000000000000000ll;

struct pos {
	int x, y, z;
	pos(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
	bool operator<(const pos &p) const {
		if (x != p.x) return x < p.x;
		if (y != p.y) return y < p.y;
		return z < p.z;
	}
};
typedef pair <ll, pos> llp;

int n, m;
vector <ii> neigh[Maxn];
ll dist[Maxn][Maxm][Maxm];
priority_queue <llp> Q;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	fill((ll*)dist, (ll*)dist + Maxn * Maxm * Maxm, Inf);
	dist[1][0][0] = 0;
	Q.push(llp(0ll, pos(1, 0, 0)));
	while (!Q.empty()) {
		pos v = Q.top().second;
		ll d = -Q.top().first; Q.pop();
		if (d != dist[v.x][v.y][v.z]) continue;
		for (int i = 0; i < neigh[v.x].size(); i++) {
			ii u = neigh[v.x][i];
			for (int j = 0; j < 2 && v.y + j < 2; j++)
				for (int l = 0; l < 2 && v.z + l < 2; l++) {
					pos nw = pos(u.first, v.y + j, v.z + l);
					ll cand = d;
					int mult = 1;
					if (j == 1) mult++;
					if (l == 1) mult--;
					cand += mult * u.second;
					if (cand < dist[nw.x][nw.y][nw.z]) {
						dist[nw.x][nw.y][nw.z] = cand;
						Q.push(llp(-cand, nw));
					}
				}
		}
	}
	for (int i = 2; i <= n; i++)
		printf("%I64d%c", dist[i][1][1], i + 1 <= n? ' ': '\n');
    return 0;
}