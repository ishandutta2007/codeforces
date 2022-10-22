#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10, M = 16, T = 1 << M, P = 1e9 + 7;
char s[N];
int n;
int dp[N][T], t1[T], t2[T], t3[T];
int ls[N], rs[N], opt[N], tot = 0;
int a[M];

int build(int l, int r) {
	if(l > r) return 0;
	int layer = 0, pos = -1;
	for(int i = l; i <= r; i++) {
		if(s[i] == '(' || s[i] == ')') {
			layer += (s[i] == '(' ? 1 : -1);
		} else if(!layer){
			pos = i;
			break;
		}
	}
	if(pos == -1) {
		return build(l + 1, r - 1);
	}
	int p = ++tot;
	if(s[pos] == '&' || s[pos] == '|') opt[p] = s[pos] == '|';
	else if(s[pos] == '?') {
		opt[p] = 2;
		if(l == r) {
			for(int x = 0; x < 8; x++) {
				dp[p][a[x]]++;
			}
		}
	} else {
		int x = ('A' <= s[pos] && s[pos] <= 'D') ? s[pos] - 'A' : s[pos] - 'a' + 4;
		dp[p][a[x]]++;
	}
	ls[p] = build(l, pos - 1), rs[p] = build(pos + 1, r);
	return p;
}
void And(int *f, int t) {
	(t += P) %= P;
	for(int i = 2; i <= T; i <<= 1) {
		for(int j = 0; j < T; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				(f[j + k] += 1ll * f[j + k + (i >> 1)] * t % P) %= P;
			}
		}
	}
	return;
}

void Or(int *f, int t) {
	(t += P) %= P;
	for(int i = 2; i <= T; i <<= 1) {
		for(int j = 0; j < T; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				(f[j + k + (i >> 1)] += 1ll * f[j + k] * t % P) %= P;
			}
		}
	}
	return;
}

void AND(int *a, int *b, int *c) {
	for(int i = 0; i < T; i++) t1[i] = a[i], t2[i] = b[i];
	And(t1, 1), And(t2, 1);
	for(int i = 0; i < T; i++) t3[i] = 1ll * t1[i] * t2[i] % P;
	And(t3, -1);
	for(int i = 0; i < T; i++) (c[i] += t3[i]) %= P;
	return;
}

void OR(int *a, int *b, int *c) {
	for(int i = 0; i < T; i++) t1[i] = a[i], t2[i] = b[i];
	Or(t1, 1), Or(t2, 1);
	for(int i = 0; i < T; i++) t3[i] = 1ll * t1[i] * t2[i] % P;
	Or(t3, -1);
	for(int i = 0; i < T; i++) (c[i] += t3[i]) %= P;
	return;
}

void dfs(int p) {
	if(!ls[p] && !rs[p]) return;
	dfs(ls[p]), dfs(rs[p]);
	for(int i = 0; i < 2; i++) {
		if(opt[p] == 2 || opt[p] == i) {
			if(i == 0) AND(dp[ls[p]], dp[rs[p]], dp[p]);
			else OR(dp[ls[p]], dp[rs[p]], dp[p]);
		}
	}
	return;
}

int main() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 16; j++) {
			if(j >> i & 1) {
				a[i] |= 1 << j;
			} else {
				a[i + 4] |= 1 << j;
			}
		}
	}
	cin >> (s + 1);
	cin >> n;
	int aim = 0, sub = 0;
	for(int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int t = a + b * 2 + c * 4 + d * 8;
		sub |= 1 << t;
		aim |= e << t;
	}
	int rt = build(1, strlen(s + 1));
	dfs(rt);
	int ns = 0;
	for(int i = 0; i < T; i++) {
		if((i & sub) == aim) {
			(ns += dp[rt][i]) %= P;
		}
	}
	cout << ns << endl;
	return 0;
}