#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
int n, k, f[30];
struct List {
	int l[maxn], r[maxn];
	void init() {
		r[0] = 1, l[n + 1] = n;
		for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
	}
	void del(int x) { l[r[x]] = l[x], r[l[x]] = r[x]; }
} a, b;
char s[maxn];
void work() {
	for (int c = 0; c < 26; ++c) f[c] = 0;
	scanf("%d%s%d", &n, s + 1, &k);
	a.init(), b.init();
	while (k--) {
		char c[2]; scanf("%s", c);
		f[c[0] - 'a'] = 1;
	}
	for (int i = 1; i <= n; ++i)
		if (!f[s[i] - 'a']) a.del(i);
	int tim = 0;
	while (a.l[n + 1]) {
		vector <int> pos;
		for (int p = a.l[n + 1]; p; p = a.l[p]) {
			int q = b.l[p];
			if (!q) continue;
			pos.push_back(q);
		}
		if (!pos.size()) break;
		++tim;
		for (int p : pos) {
			if (f[s[p] - 'a']) a.del(p);
			b.del(p);
		}
	}
	printf("%d\n", tim);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}