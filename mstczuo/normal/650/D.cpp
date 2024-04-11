# include <cstdio>
# include <cstring>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 400010;
const int inf = ~0u>>2;

int a[maxn];
int n, m;

int c[maxn];
int cnt[maxn];
int f[maxn], g[maxn];

int lv[maxn], rv[maxn];
int lf[maxn], rf[maxn];

struct query {
	int id, p, v;
	void init(int k) {
		id = k;
		scanf("%d%d", &p, &v);
	}
	bool operator<(const query&et) const {
		return p < et.p;
	}
}q[maxn];

bool cmp_id(const query&a,const query&b) {
	return a.id < b.id;
}

int calc_l(int len,int val) {
	int l = 0, r = len + 1, mid;
	while(r - l > 1) 
		(c[mid = (l + r) / 2] < val) ? l = mid : r = mid;
	return r;
}

int calc_r(int len,int val) {
	int l = 0, r = len + 1, mid;
	while(r - l > 1) 
		(c[mid = (l + r) / 2] > val) ? l = mid : r = mid;
	return r;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) q[i].init(i);
	sort(q+1, q+m+1);

	int len;

	c[0] = -inf; len = 0;
	for(int i = 1, j = 1; i <= n; ++i) {
		for(;j <= m && q[j].p == i;++j) 
			lf[q[j].id] = calc_l(len, q[j].v);
		f[i] = calc_l(len, a[i]);
		lv[i] = c[f[i]-1];
		(f[i] > len) ? c[++len] = a[i]: c[f[i]] = min(c[f[i]], a[i]);
	}

	c[0] = inf; len = 0;
	for(int i = n, j = m; i >= 1; --i) {
		for(;j >= 1 && q[j].p == i;--j) 
			rf[q[j].id] = calc_r(len, q[j].v);
		g[i] = calc_r(len, a[i]);
		rv[i] = c[g[i]-1];
		(g[i] > len) ? c[++len] = a[i]: c[g[i]] = max(c[g[i]], a[i]);
	}

	for(int i = 1; i <= n; ++i) 
		if(f[i] + g[i] == len + 1) cnt[f[i]] += 1;

	sort(q+1, q+m+1, cmp_id);
	for(int i = 1; i <= m; ++i) {
		int p = q[i].p, v = q[i].v, ans;
		if(lf[i] + rf[i] - 1 > len) {
			ans = len + 1;
		} else if(lf[i] + rf[i] - 1 == len) {
			ans = len;
		} else if(f[p] + g[p] == len + 1 && cnt[f[p]] == 1 && (v <= lv[p]|| v >= rv[p])) {
			ans = len - 1;
		} else {
			ans = len;
		}
		printf("%d\n", ans);
	}

	return 0;
}