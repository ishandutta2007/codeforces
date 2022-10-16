// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 55;

int n, q, a[N], tot, t;

vector<int> e[N], b[N];

void inline work(vector<int> w) {
	if (w.size() == 1) e[t].clear(), --t;
	tot = 0;
	int u = 1;
	for (int v: w) {
		++tot;
//		cout << v << " ";
		while (v--) b[tot].pb(a[u++]);
	}
//	puts(" done");
	for (int i = 1; i <= tot / 2; i++)
		swap(b[i], b[tot - i + 1]);
	u = 1;
	for (int i = 1; i <= tot; i++) {
		for (int v: b[i]) a[u++] = v;
		b[i].clear();
	}
//	for (int i = 1; i <= n; i++) cout << a[i] << " ";
//	cout << endl;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	int c = 0;
	for (int i = 1; i < n; i++) {
		if (!c) {
			if (a[i] == i) {
				continue;
			}
			int p = -1;
			for (int j = 1; j <= n; j++)
				if (a[j] == i) p = j;
			++t;
			for (int j = 1; j < i; j++)
				e[t].pb(1);
			e[t].pb(p - (i - 1));
			if (n - p) e[t].pb(n - p);
			work(e[t]);
		} else {
			if (a[n - i + 1] == i) {
				continue;
			}
			int p = -1;
			for (int j = 1; j <= n; j++)
				if (a[j] == i) p = j;
			++t;
			if (p > 1) e[t].pb(p - 1);
			e[t].pb((n - i + 1) - p + 1);
			for (int j = 1; j < i; j++)
				e[t].pb(1);
			work(e[t]);
		}
		c ^= 1;
	}
	if (c) {
		++t;
		for (int i = 1; i <= n; i++) e[t].pb(1);
		work(e[t]);
	}
	for (int i = 1; i <= n; i++) assert(a[i] == i);
	printf("%d\n", t);
	for (int i = 1; i <= t; i++) {
		printf("%lu ", e[i].size());
		for (int v: e[i]) printf("%d ", v);
		puts("");
	}
    return 0;
}