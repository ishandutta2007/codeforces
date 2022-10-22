#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define PI pair<int, int>
#define pb push_back
using namespace std;
typedef long long i64;
typedef double db;
const int N = 150 + 10, oo = 0x3f3f3f3f;
int n, m, a[N], b[N], d[N], ord[N];
struct Mat {
	bitset<N> f[N], g[N];
	Mat() {}
	
	void set(int x, int y, int v) {
		f[x][y] = g[y][x] = v;
		return;
	}
		
	friend Mat operator * (const Mat a, const Mat b) {
		Mat c;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				c.set(i, j, (a.f[i] & b.g[j]).any());
			}
		}
		return c;
	}
}trans;

Mat power(Mat a, int b, Mat c) {
	for(; b; b >>= 1, a = a * a)
		if(b & 1)
			c = c * a;
	return c;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &a[i], &b[i], &d[i]), ord[i] = i;
	sort(ord + 1, ord + m + 1, [&](int x, int y) {
		return d[x] < d[y];
	});
	Mat start;
	start.set(1, 1, 1);
	trans.set(n, n, 1);
	int pos = -1;
	for(int i = 1, r = 1; i <= m; i = r) {
		int x = ord[i];
		Mat tmp = power(trans, d[x] - d[ord[i - 1]], start);
		if(tmp.f[1][n]) {
			pos = i - 1;
			break;
		}
		start = tmp;
		while(r <= m && d[ord[r]] <= d[x]) {
			trans.set(a[ord[r]], b[ord[r]], 1);
			r++;
		}
	}
	if(pos == -1) {
		Mat tmp = power(trans, oo - d[ord[m]], start);
		if(!tmp.f[1][n]) {
			puts("Impossible");
			return 0;
		}
		pos = m;
	}
	int ans = d[ord[pos]];
	for(int i = 7; i >= 0; i--) {
		Mat tmp = power(trans, 1 << i, start);
		if(!tmp.f[1][n]) ans += 1 << i, start = tmp;
	}
	printf("%d\n", ans + 1);
	return 0;
}