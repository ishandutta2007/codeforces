#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int N = 2e5 + 10;
int n, p[N], vis[N], tot = 0;
vector<int> a, b, cir[N];

void modify(int x, int y) {a.push_back(x), b.push_back(y), swap(p[x], p[y]), p[x] = -p[x], p[y] = - p[y];}

void circle(vector<int> l, vector<int> r) {
	int n = l.size(), m = r.size();
	if(n > m) swap(n, m), swap(l, r);
	modify(l[n - 1], r[m - 1]);
	rep(i, 0, n - 2) modify(r[m - 1], l[i]);
	rep(i, 0, m - 2) modify(l[n - 1], r[i]);
	modify(l[n - 1], r[m - 1]);
	return;
}

void solve() {
	for(int i = 2; i <= tot; i += 2) circle(cir[i - 1], cir[i]);
	if(tot & 1) {
		vector<int> own;
		rep(i, 1, n) {
			if(p[i] == i) {
				own.push_back(i);
				break;
			}
		}
		circle(own, cir[tot]);
	}
	return;
}

void corn() {
	rep(i, 1, n - 2) modify(cir[1][0], cir[1][i]);
	modify(cir[1][1], cir[1][n - 1]);
	modify(cir[1][n - 1], cir[1][0]);
	modify(cir[1][0], cir[1][1]);
	return;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(u, 1, n) {
		if(vis[u]) continue;
		tot++;
		int x = u;
		while(!vis[x]) vis[x] = 1, cir[tot].push_back(x), x = p[x];
	}
	if(tot ^ 1) solve();
	else corn();
	rep(i, 0, n - 1) assert(i == p[i]);
	printf("%d\n", SZ(a));
	rep(i, 0, SZ(a) - 1) printf("%d %d\n", a[i], b[i]);
	return 0;
}