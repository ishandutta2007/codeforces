#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef tuple <int, int, int> piii;

const int maxn = 510, inf = 1e9;
int U[maxn][maxn],D[maxn][maxn],L[maxn][maxn],R[maxn][maxn],n,k;
void add_ver(int r, int c1) { D[r - 1][c1]++, U[r][c1]++; }
void add_hor(int c, int r1) { R[r1][c - 1]++, L[r1][c]++; }
int dis[maxn][maxn];

priority_queue <piii, vector <piii>, greater <piii> > pq;
void ins(int x, int y, int val) {
	if (x < 0 || x > k || y < 0 || y > k || dis[x][y] <= val) return;
	dis[x][y] = val;
	pq.push(make_tuple(val, x, y));
}

void work() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j <= k; ++j)
			U[i][j] = D[i][j] = L[i][j] = R[i][j] = 0, dis[i][j] = inf;
	for (int i = 1; i <= n; ++i) {
		int r1,c1,r2,c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		if (r1 == r2) {
			if (c1 > c2) swap(c1, c2);
			add_ver(r1, c1), add_ver(k - r1 + 1, k - c2 + 1);
		}
		else {
			if (r1 > r2) swap(r1, r2);
			add_hor(c1, r1), add_hor(k - c1 + 1, k - r2 + 1);
		}
	}
	dis[0][0] = 0;
	pq.push(make_tuple(0, 0, 0));
	while (!pq.empty()) {
		int x, y, val; tie(val, x, y) = pq.top(); pq.pop();
		if (val > dis[x][y]) continue;
		ins(x + 1, y, val + D[x][y]), ins(x, y + 1, val + R[x][y]);
		ins(x - 1, y, val + U[x][y]), ins(x, y - 1, val + L[x][y]);
	}
	printf("%d\n", n - dis[k / 2][k / 2]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}