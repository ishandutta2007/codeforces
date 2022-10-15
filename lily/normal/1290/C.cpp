#include <bits/stdc++.h>
using namespace std;
#define read(a) scanf("%d", &a)

#define N 301111

int n, K, ans;
char s[N];
vector <int> b[N];
int f[N], v[N], L[N], siz[N];

int getf(int x) {
	if (f[x] == x) return x;
	int ff = getf(f[x]);
	v[x] ^= v[f[x]];
	return f[x] = ff;
}

void merge(int x, int y, int val) {
	if (getf(x) == getf(y)) return;
	int fx = getf(x), fy = getf(y);
	val ^= v[x] ^ v[y];
	f[fx] = fy;
	v[fx] = val;
	ans -= min(L[fx], siz[fx] - L[fx]);
	ans -= min(L[fy], siz[fy] - L[fy]);
	siz[fy] += siz[fx];
	L[fy] += val ? siz[fx] - L[fx] : L[fx];
	ans += min(L[fy], siz[fy] - L[fy]);
}

int main() {
	read(n); read(K);
	scanf("%s", s + 1 );
	for (int i = 1; i <= K; i++) {
		int c, x;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			b[x].push_back(i);
		}
	}
	for (int i = 1; i <= K; i++) f[i] = i, L[i] = 1, v[i] = 0, siz[i] = 1;
	f[0] = 0, L[0] = 0, v[0] = 0, siz[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		if (b[i].size() == 0);
		else if (b[i].size() == 1) {
			if (s[i] == '0') merge(b[i][0], 0, 0);
			else 			 merge(b[i][0], 0, 1);
		}
		else {
			if (s[i] == '0') merge(b[i][0], b[i][1], 1);
			else 			 merge(b[i][0], b[i][1], 0);
		}
		printf("%d\n", ans);
	}
}