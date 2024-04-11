#include<bits/stdc++.h>

using namespace std;

#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define debug(x) cerr << #x <<" " << x << endl
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
const int N = 1e6 + 10;
struct Edge {
	int u, v, w;
}e[N];
int n, m;
int fa[N], cnt[N], siz[N];

int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }

int unite(int x, int y) {
	x = gf(x), y = gf(y);
	if(x == y) {
		if(cnt[x] + 1 <= siz[x]) {
			cnt[x]++;
			return 1;
		}
		return 0;
	}
	if(siz[x] + siz[y] >= cnt[x] + cnt[y] + 1) {
		fa[x] = y, cnt[y] += cnt[x] + 1, siz[y] += siz[x];
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, [&] (Edge a, Edge b) { return a.w > b.w; });
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1, cnt[i] = 0;
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		if(unite(e[i].u, e[i].v)) ans += e[i].w;
	}
	cout << ans << endl;
	return 0;
}