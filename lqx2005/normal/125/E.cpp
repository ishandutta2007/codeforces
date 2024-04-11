#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n, m, k;
int fa[N];
int u[N], v[N], w[N], id[N], vis[N];

int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }

int check(int x) {
	for(int i = 1; i <= m; i++) vis[i] = 0;
	for(int i = 1; i <= m; i++) if(u[i] == 1) w[i] += x;
	sort(id + 1, id + m + 1, [&] (int a, int b) {
		if(w[a] != w[b]) return w[a] < w[b];
		return u[a] > u[b];
	});
	for(int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		int x = id[i];
		if(gf(u[x]) == gf(v[x])) continue;
		if(u[x] == 1) cnt++, vis[x] = 1;
		fa[gf(u[x])] = gf(v[x]);
	}
	for(int i = 1; i <= m; i++) if(u[i] == 1) w[i] -= x;
	return cnt;
}

void output(int x) {
	for(int i = 1; i <= m; i++) if(u[i] == 1) w[i] += x;
	sort(id + 1, id + m + 1, [&] (int a, int b) {
		if(w[a] != w[b]) return w[a] < w[b];
		return u[a] < u[b];
	});
	for(int i = 1; i <= n; i++) fa[i] = i;
	vector<int> ans;
	int cnt = 0;
	for(int i = 1; i <= m; i++) cnt += vis[i];
	for(int i = 1; i <= m; i++) {
		int x = id[i];
		if(gf(u[x]) == gf(v[x])) continue;
		if(u[x] == 1 && !vis[x] && cnt == k) continue;
		ans.push_back(x);
		if(u[x] == 1 && !vis[x]) cnt++;
		fa[gf(u[x])] = gf(v[x]);
	}
	if(SZ(ans) < n - 1 || cnt != k) return printf("-1\n"), void();
	else {
		printf("%d\n", n - 1);
		for(int i = 0; i < n - 1; i++) printf("%d%c", ans[i], " \n"[i == n - 2]);
	}
	for(int i = 1; i <= m; i++) if(u[i] == 1) w[i] -= x;
	return;
}


int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		id[i] = i;
		cin >> u[i] >> v[i] >> w[i];
		if(u[i] > v[i]) swap(u[i], v[i]);
	}
	int L = -N, R = N, best = - N - 1;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(check(mid) <= k) best = mid, R = mid - 1;
		else L = mid + 1;
	}
	check(best);
	output(best);
	return 0;
}