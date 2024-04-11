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

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int inf = 1e9;
map<P, int> vis, used, str;
set<P> crd;
int n;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int check(vector<P> cd) {
	used.clear(), str.clear();
	rep(i, 0, SZ(cd) - 1) str[cd[i]] = 1;
	vis.clear(), crd.clear();
	rep(i, 0, SZ(cd) - 1) vis[cd[i]] = 4, crd.insert(cd[i]);
	int ans = 0;
	int mnx = inf, mxx = -inf, mxy = -inf, mny = inf;
	while(!crd.empty()) {
		P u = *crd.begin();
		used[u] = 1;
		ckmin(mnx, u.x), ckmin(mny, u.y), ckmax(mxx, u.x), ckmax(mxy, u.y);
		ans++;
		vis[u] = -inf;
		crd.erase(crd.begin());
		for(int i = 0; i < 8; i++) {
			P v = u;
			v.x += dx[i], v.y += dy[i];
			vis[v]++;
			if(vis[v] >= 4) crd.insert(v);
		}
	}
//	printf("%d\n", ans);
//	rep(i, mnx, mxx) {
//		rep(j, mny, mxy) printf("%d ", used[mp(i, j)]);
//		printf("\n");
//	}
	return ans;
}

vector<P> corn(int n) {
	vector<P> id;
	rep(i, 1, n / 2) id.push_back(mp(i, 0));
	n -= n / 2;
	rep(i, 1, n) id.push_back(mp(i, 1));
	return id;
}

vector<P> test(int h) {
	vector<P> id;
	id.clear();
	int m = h / 2;
	rep(i, 1, m) id.push_back(mp(i, 0));
	rep(i, 1, h - m) id.push_back(mp(i, 1));
	int k = n - h, mdr = (m + 1) / 2, mdl = (h - m + 1) / 2;
	int R = m / 4 - (m % 4 == 0), L = (h - m) / 4 - ((h - m) % 4 == 0);
	if(k / 2 > 1) {
		rep(i, - R - k / 2, - R - 1) id.push_back(mp(mdr, i));
		k -= k / 2;
	}
	rep(i, L + 2, L + k + 1) id.push_back(mp(mdl, i));
	return id;
}

void quit(vector<P> id) {
	assert(SZ(id) == n);
	assert(check(id) >= n * n / 10);
	rep(i, 0, SZ(id) - 1) printf("%d %d\n", id[i].x, id[i].y);
	exit(0);
}

int main() {
	scanf("%d", &n);
	vector<P> id;
	if(n <= 14) quit(corn(n));
	if(n <= 50) {
		int mx = 0;
		vector<P> id;
		rep(i, 1, n) {
			vector<P> tmp = test(i);
			int t = check(tmp);
			if(t > mx) mx = t, id = tmp;
		}
		quit(id);
	}
	int m = n * 4 / 5;
	quit(test(m));
	return 0;
}