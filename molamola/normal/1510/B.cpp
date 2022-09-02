#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

namespace Hung {
	const int MX = 1030;
	const int INF = 1e9;
	// IMPORTANT : n <= m
	int a[MX][MX], n, m;
	void init(int nn, int mm) {
		n = nn; m = mm;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = 0;
	}
	void set_value(int x, int y, int val) { a[x][y] = -val; }
	int solve(vector <int> &ans) {
		vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
		for (int i=1; i<=n; ++i) {
			p[0] = i;
			int j0 = 0;
			vector<int> minv (m+1, INF);
			vector<char> used (m+1, false);
			do {
				used[j0] = true;
				int i0 = p[j0], delta = INF, j1;
				for (int j=1; j<=m; ++j) if (!used[j]) {
						int cur = a[i0][j]-u[i0]-v[j];
						if (cur < minv[j]) {
							minv[j] = cur, way[j] = j0;
						}
						if (minv[j] < delta) {
							delta = minv[j], j1 = j;
						}
					}
				for (int j=0; j<=m; ++j) {
					if (used[j]) {
						u[p[j]] += delta, v[j] -= delta;
					}
					else {
						minv[j] -= delta;
					}
				}
				j0 = j1;
			} while (p[j0] != 0);
			do {
				int j1 = way[j0];
				p[j0] = p[j1];
				j0 = j1;
			} while (j0);
		}
		ans.resize(n + 1);
		for(int j=1;j<=m;++j) {
			ans[p[j]] = j;
		}
		return -v[0];
	}
}

int d, n, a[1100], prv[1100], nxt[1100], c[1030][1030];

int main() {
	scanf("%d%d", &d, &n);
	Hung::init(n, n);
	rep(i, n) {
		char ch[12];
		scanf("%s", ch);
		rep(j, d) if(ch[j] == '1') a[i] |= 1<<j;
	}
	rep(i, n) rep(j, n) {
		if(a[i] < a[j] && (a[j] & a[i]) == a[i]) {
			Hung::set_value(i + 1, j + 1, __builtin_popcount(a[i]));
			c[i+1][j+1] = 1;
		}
	}
	vector <int> tr;
	Hung::solve(tr);
	for(int i=1;i<=n;i++) {
		prv[i] = nxt[i] = -1;
	}
	for(int i=1;i<=n;i++) {
		int j = tr[i];
		if(c[i][j]) nxt[i] = j, prv[j] = i;
	}
	string ans;
	for(int i=1;i<=n;i++) {
		if(nxt[i] == -1) {
			vector <int> w;
			for(int x=i;x!=-1;x=prv[x]) w.pb(a[x - 1]);
			reverse(all(w));
			int s = 0;
			for(int e : w) {
				rep(b, d) {
					if((e & 1<<b) && !(s & 1<<b)) {
						s |= 1<<b;
						ans.pb('0' + b);
					}
				}
			}
			ans.pb('R');
		}
	}
	ans.pop_back();
	printf("%d\n", szz(ans));
	for(char c : ans) printf("%c ", c); puts("");
	return 0;
}