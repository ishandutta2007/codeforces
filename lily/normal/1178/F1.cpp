#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define MOD 998244353
#define N 505
int n, m;
int a[N], f[N][N];

int F(int l, int r) {
	if (l >= r) return 1;
	if (f[l][r] != -1) return f[l][r]; 
	LL lans = 0, rans = 0; int mi = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < a[mi]) mi = i;
	}
	for (int i = l; i <= mi; i++) (lans += ((LL)F(l, i - 1) * F(i, mi - 1) % MOD)) %= MOD;
	for (int i = mi; i <= r; i++) (rans += ((LL)F(mi + 1, i) * F(i + 1, r) % MOD) ) %= MOD; 
	lans %= MOD;
	rans %= MOD;
	return f[l][r] = int(lans * rans % MOD);
}

int main() {
	memset(f, -1, sizeof f);
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	cout << F(1, n) << endl;
}