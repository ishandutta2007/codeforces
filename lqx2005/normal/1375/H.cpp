#include <bits/stdc++.h>
#define PI pair<int, int>
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
#define sz(a) int((a).size())
using namespace std;
const int N = (1 << 12) + 10, Q = (1 << 16) + 10, T = 2.2e6 + 10;
int n, q, a[N], b[N];
int cntE, x[T], y[T];
int ans[Q];
vector<int> pos[N << 1];
map<PI, int> id[N << 1];
int read() {
	int x = 0;
	char w;
	for(w = getchar(); w < '0' || w > '9'; w = getchar());
	for(; '0' <= w && w <= '9'; w = getchar()) x = x * 10 + w - '0';
	return x;
} 

void print(int x, char text = 0) {
	if(x == 0) putchar('0');
	else {
		static int num[38];
		int tot = 0;
		for(; x > 0; num[++tot] = x % 10, x /= 10);
		for(int i = tot; i >= 1; i--) putchar('0' + num[i]);
	}
	if(text) putchar(text);
	return;
} 

int merge(int p, int q) {
	if(p == 0 || q == 0) return p + q;
	cntE++;
	x[cntE] = p, y[cntE] = q;
	return cntE;
}

void build(int p, int l, int r) {
	if(l == r) {
		pos[p].push_back(b[l]);
		id[p][{b[l], b[l]}] = b[l];
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pos[p] = pos[lc];
	pos[p].insert(pos[p].end(), pos[rc].begin(), pos[rc].end());
	sort(pos[p].begin(), pos[p].end());
	return;
}

int query(int p, int l, int r, int L, int R) {
	int pl = lower_bound(pos[p].begin(), pos[p].end(), L) - pos[p].begin();
	int pr = upper_bound(pos[p].begin(), pos[p].end(), R) - pos[p].begin() - 1;
	if(pl > pr) return 0;
	pl = pos[p][pl], pr = pos[p][pr];
	if(id[p].find({pl, pr}) != id[p].end()) return id[p][{pl, pr}];
	id[p][{pl, pr}] = merge(query(lc, l, mid, pl, pr), query(rc, mid + 1, r, pl, pr));
	return id[p][{pl, pr}];
}

int main() {
	n = read(), q = read();
	cntE = n;
	for(int i = 1; i <= n; i++) a[i] = read(), b[a[i]] = i;
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read();
		ans[i] = query(1, 1, n, l, r);
	}
	print(cntE, '\n');
	for(int i = n + 1; i <= cntE; i++) print(x[i], ' '), print(y[i], '\n');
	for(int i = 1; i <= q; i++) print(ans[i], ' ');
	putchar('\n');
	return 0;
}