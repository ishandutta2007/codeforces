#include <bits/stdc++.h>
#define sz(a) int((a).size())
typedef long long i64;
using namespace std;
const int N = 1e3 + 10, K = 10;
struct Vec {
	i64 x, y;
	Vec() {x = y = 0; }
	Vec(i64 X, i64 Y) {
		x = X, y = Y;
	}
	void in() { cin >> x >> y; }
	void out() {cout << "point: "<< x <<" " << y << endl; }
	friend Vec operator - (const Vec a, const Vec b) {
		return Vec(a.x - b.x, a.y - b.y);
	}
	
	friend i64 operator * (const Vec a, const Vec b) {
		return a.x * b.y - a.y * b.x;
	}
	
	friend i64 operator / (const Vec a, const Vec b) {
		return a.x * b.x + a.y * b.y;
	}
}a[K], b[N], c[N];
int k, n, id[N], to[N][K], vis[N], stk[N], top = 0;
int on(Vec a, Vec b, Vec c) {
	return (c - a) * (b - a) == 0 && (a - b) / (c - b) < 0;
}

int dfs(int x, int &now) {
	if(now >= k) return 0;
	int p = id[++now];
	stk[++top] = x, vis[x] = 1;
	for(int u = to[x][p]; u; u = to[u][p]) {
		if(vis[u]) continue;
		if(!dfs(u, now)) return 0;
	}
	return 1;
}

int main() {
	cin >> k >> n;
	for(int i = 1; i <= k; i++) a[i].in();
	for(int i = 1; i <= n; i++) b[i].in();
	for(int i = 1; i <= k; i++) {
		for(int p = 1; p <= n; p++) {
			for(int q = 1; q <= n; q++) {
				if(on(a[i], b[q], b[p]) && (!to[p][i] || on(a[i], b[to[p][i]], b[q]))) {
					to[p][i] = q;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) id[j] = j;
		do {
			for(int j = 1; j <= top; j++) vis[stk[j]] = 0;
			top = 0;
			int now = 0;
			if(dfs(i, now)) {
				ans++;
				break;
			}
		} while(next_permutation(id + 1, id + k + 1));
	}
	cout << ans << endl;
	return 0;
}