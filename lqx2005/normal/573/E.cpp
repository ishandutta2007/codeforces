#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
#define x first
#define y second
#define mp make_pair
#define vec pair<i64, i64>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
const i64 oo = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(__builtin_ia32_rdtsc());
int n, a[N], tot = 0, pos[N];
i64 sum[N], cnt[N];
int ls[N], rs[N];
int siz[N], rnd[N], etot = 0;
i64 val[N], tag[N];

int newd(i64 v) {
	int u = ++etot;
	val[u] = v, tag[u] = 0;
	siz[u] = 1, rnd[u] = rng();
	return u; 
}

void upd(int p) {
	siz[p] = siz[ls[p]] + siz[rs[p]] + 1;
	return;
}

void pushd(int p) {
	if(!tag[p]) return;
	if(ls[p]) val[ls[p]] += tag[p], tag[ls[p]] += tag[p];
	if(rs[p]) val[rs[p]] += tag[p], tag[rs[p]] += tag[p];
	tag[p] = 0;
	return;
}

int merge(int a, int b) {
	if(!a || !b) return a + b;
	pushd(a), pushd(b);
	if(rnd[a] < rnd[b]) {
		rs[a] = merge(rs[a], b);
		return upd(a), a;
	}
	ls[b] = merge(a, ls[b]);
	return upd(b), b;
}

void split(int u, int k, int &x, int &y) {
	if(!u) return x = y = 0, void();
	pushd(u);
	if(siz[ls[u]] >= k) {
		y = u;
		split(ls[u], k, x, ls[u]);
	} else {
		k -= siz[ls[u]] + 1;
		x = u;
		split(rs[u], k, rs[u], y);
	}
	return upd(u);
}

int find(int p, i64 c, i64 a, i64 d) {
	if(!p) return 0;
	pushd(p);
	if(val[p] - c - d - a * (1 + siz[ls[p]]) < 0) return find(ls[p], c, a, d);
	return find(rs[p], c, a, d + a * (siz[ls[p]] + 1)) + siz[ls[p]] + 1;
}

void dfs(int p) {
	if(!p) return;
	pushd(p);
	dfs(ls[p]);
	printf("%lld ", val[p]);
	dfs(rs[p]);
	return;
}

int main() {
	scanf("%d", &n);
	i64 ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1], cnt[i] = cnt[i - 1];
		if(a[i] >= 0) sum[i] += a[i], cnt[i]++, ans += cnt[i] * a[i];
		else pos[++tot] = i;
	}
	if(tot == 0) {
		printf("%lld\n", ans);
		return 0;
	}
	int rt = 0;
	for(int i = 1; i <= tot; i++) {
		i64 c = sum[n] - sum[pos[i]] + cnt[pos[i]] * a[pos[i]];
		i64 a = ::a[pos[i]];
		int s = find(rt, c, a, 0);
		int x, y;
		split(rt, s, x, y);
		if(y) {
			i64 d = c + a * (s + 1);
			tag[y] += a, val[y] += a;
			y = merge(newd(d), y);
		} else {
			y = newd(c + a * (siz[x] + 1));
		}
		rt = merge(x, y);
	}
	while(siz[rt] > 0) {
		int x, y;
		split(rt, 1, x, y);
		if(val[x] >= 0) ans += val[x], rt = y;
		else break;
	}
	printf("%lld\n", ans);
    return 0;
}