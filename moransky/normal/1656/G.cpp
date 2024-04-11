// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, a[N], c[N], now, mid, f[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	f[find(x)] = find(y);
}

vector<int> ps[N];

int p[N];

int v[N], t, w[N];

void inline mg(int a, int c) {
	int b = n - a + 1;
	int d = n - c + 1;
	int ta = p[a], tb = p[b], tc = p[c], td = p[d];
	p[a] = tc, p[d] = ta, p[b] = td, p[c] = tb;
}

void inline work() {
	if (n & 1) {
		sort(ps[now].begin(), ps[now].end());
		for (int v: ps[now])
			if (v != mid) {
				p[mid] = v;
				ps[now].erase(lower_bound(ps[now].begin(), ps[now].end(), v));	
				break;
			}
	}
	
	for (int i = 1, j = 1; i <= n / 2; i++) {
		while (ps[j].size() == 0) j++;
		p[i] = ps[j].back(); ps[j].pop_back();
		p[n - i + 1] = ps[j].back(); ps[j].pop_back();	
	}
	for (int i = 1; i <= n; i++) merge(i, p[i]);
	for (int i = 1; i <= n / 2; i++) {
		int a = i, b = n - i + 1;
		if (find(a) != find(b)) {
			merge(a, b);
			int ta = p[a], tb = p[b];
			p[a] = tb, p[b] = ta;
		}
	}
	t = 0;
	for (int i = 1; i <= n / 2; i++)
		w[find(i)] = i;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) v[t++] = w[i];
	}
	for (int i = 1; i < t; i++) {
		mg(v[0], v[i]);
	}
	puts("YES");
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) merge(i, p[i]), printf("%d ", p[i]), assert(a[p[i]] == a[p[n - i + 1]]);
	bool o = 1;
	for (int i = 2; i <= n; i++)
		if (find(i) != find(1)) o = 0;
	assert(o);
	puts("");
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]), f[i] = i, c[a[i]]++, ps[a[i]].pb(i);
		int o = 0; mid = (n + 1) / 2;
		for (int i = 1; i <= n; i++) {
			if (c[i] & 1) o++, now = i;
		}
		if ((n % 2 == 0 && o) || (n % 2 && o != 1) || (n % 2 && c[a[mid]] == 1)) {
			puts("NO");
		} else {
			work();
		}
		for (int i = 1; i <= n; i++) c[a[i]] = 0, ps[a[i]].clear();
	}
    return 0;
}