#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 3e6 + 10;
int trie[maxn][2],tot;
void ins(int x) {
	int nw = 1;
	for (int bit = 16; bit >= 0; --bit) {
		int c = (x >> bit) & 1;
		if (!trie[nw][c]) trie[nw][c] = ++tot, trie[tot][0] = trie[tot][1] = 0;
		nw = trie[nw][c];
	}
}
int query(int x, int mx) {
	int nw = 1, res = 0;
	for (int bit = 16; bit >= 0; --bit) {
		int c = (x >> bit) & 1;
		if (trie[nw][c ^ mx]) nw = trie[nw][c ^ mx], res ^= mx << bit;
		else nw = trie[nw][c ^ mx ^ 1], res ^= (mx ^ 1) << bit;
	}
	return res;
}
int l,r,a[maxn];
void work() {
	scanf("%d%d", &l, &r);
	trie[tot = 1][0] = trie[1][1] = 0;
	int n = r - l + 1;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ins(a[i]);
	for (int i = 1; i <= n; ++i) {
		int x = a[i] ^ l;
		if (query(x, 0) == l && query(x, 1) == r) return printf("%d\n", x), void();
	}
	// for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}