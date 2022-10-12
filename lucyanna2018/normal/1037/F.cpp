#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

struct modular_arithmetic {
	int mod;

	modular_arithmetic() {
		mod = 1000000007;
	}
	//No specific settings.
	int add(int x, int y) { return (x += y)<mod ? x : x - mod; }
	int sub(int x, int y) { return (x -= y) >= 0 ? x : x + mod; }
	int mul(int x, int y) { return (int)((long long int)x*y%mod); }
	int pw(int base, int p) {
		int res = 1, mu = base % mod;
		for (;p>0;p /= 2) {
			if (p & 1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
	int rev(int x) { return pw(x, mod - 2); }
};
modular_arithmetic ma;

#define ran 1002222

int n, k;
int c[ran], a[ran * 4];
void build(int i, int s, int e) {
	if (s == e) {
		a[i] = c[s];
		return;
	}
	int m = (s + e) / 2;
	build(i * 2, s, m);
	build(i * 2 + 1, m + 1, e);
	a[i] = max(a[i * 2], a[i * 2 + 1]);
}
int query(int i, int s, int e, int l, int r) {
	if (s == l && e == r)return a[i];
	int m = (s + e) / 2;
	if (r <= m)return query(i * 2, s, m, l, r);
	if (l > m)return query(i * 2 + 1, m + 1, e, l, r);
	return max(query(i * 2, s, m, l, m), query(i * 2 + 1, m + 1, e, m + 1, r));
}

pair<int, int> d[ran];int ld;

int lef[ran], rig[ran];
int ancestor(int*ace, int x) {
	return x - ace[x] ? ace[x] = ancestor(ace, ace[x]) : x;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	build(1, 1, n);
	--k;
	int res = 0;
	for (int j = 1; j <= k; j++) {
		ld = 0;
		for (int i = j; i + k <= n; i += k) {
			++ld;
			d[ld] = make_pair(query(1, 1, n, i, i + k), ld);
		}
		if (ld == 0)continue;
		sort(d + 1, d + ld + 1);
		for (int i = 0; i <= ld + 1; i++) {
			lef[i] = rig[i] = i;
		}
		for (int i = 1; i <= ld; i++) {
			int pos = d[i].second;
			lef[pos] = ancestor(lef, pos - 1);
			rig[pos] = ancestor(rig, pos + 1);
			int R = ancestor(rig, pos) - pos;
			int L = pos - ancestor(lef, pos);
			res = ma.add(res, ma.mul(ma.mul(L, R), d[i].first));
		}
	}
	printf("%d\n", res);
	return 0;
}