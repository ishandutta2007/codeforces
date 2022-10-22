#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define sz(a) int((a).size())
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e3 + 10;
int n, m, q, id1[N][N], sd1[N][N], id2[N][N], sd2[N][N], tot = 0;
int rev[N][N];
set<int> s[N * 4];
int len[N * 4];

i64 s2(int n) {return 1ll * n * (n - 1) / 2; }

void add(int x, int y, i64 &ans) {
	auto it = s[x].lower_bound(y);
	int l = *(--it);
	int r = *(++it);
	ans -= s2(r - l - 1);
	s[x].insert(y);
	ans += s2(y - l - 1) + s2(r - y - 1);
	return;
}

void del(int x, int y, i64 &ans) {
	s[x].erase(y);
	auto it = s[x].lower_bound(y);
	int l = *(--it);
	int r = *(++it);
	ans -= s2(y - l - 1) + s2(r - y - 1);
	ans += s2(r - l - 1);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++) {
		tot++;
		int cnt = 0;
		for(int x = 1, y = i; x <= n && y <= m; ) {
			if(!id1[x][y]) {
				id1[x][y] = ++cnt;
				sd1[x][y] = tot;
			} else {
				id2[x][y] = ++cnt;
				sd2[x][y] = tot;
			}
			if(cnt & 1) y++;
			else x++;
		}
		len[tot] = cnt;
	}
	for(int i = 1; i <= n; i++) {
		tot++;
		int cnt = 0;
		for(int x = i, y = 1; x <= n && y <= m; ) {
			if(!id1[x][y]) {
				id1[x][y] = ++cnt;
				sd1[x][y] = tot;
			} else {
				id2[x][y] = ++cnt;
				sd2[x][y] = tot;
			}
			if(cnt & 1) x++;
			else y++;
		}
		len[tot] = cnt;
	}
	i64 ans = 0;
	for(int i = 1; i <= tot; i++) {
		ans += s2(len[i]);
		s[i].insert(0);
		s[i].insert(len[i] + 1);
	}
	int all = n * m;
	for(int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		all -= !rev[x][y];
		if(rev[x][y]) {
			del(sd1[x][y], id1[x][y], ans);
			del(sd2[x][y], id2[x][y], ans);
			rev[x][y] ^= 1;
		} else {
			add(sd1[x][y], id1[x][y], ans);
			add(sd2[x][y], id2[x][y], ans);
			rev[x][y] ^= 1;
		}
		all += !rev[x][y];
		cout << ans + all << endl;
	}
	return 0;
}