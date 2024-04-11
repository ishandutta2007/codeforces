#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 1e5 + 10;
int n,a[maxn],opt;

void input() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	string s; cin >> s;
	for(char c : s) opt |= (c == '+') | ((c == '-') << 1) | ((c == '*') << 2);
}

void solve1() {
	char b[8];
	b[1] = '+', b[2] = '-', b[4] = '*';
	for(int i = 1; i <= n; ++i)
		printf("%d%c", a[i], i == n ? '\n' : b[opt & (-opt)]);
} // + & - & * & +-

void solve2() {
	printf("%d", a[1]);
	for(int i = 2; i <= n; ++i)
		if(a[i] == 0) printf("-0");
		else printf("*%d", a[i]);
} // -*

void solve3_0range(int l, int r) {
	char ans[maxn];
	int L,R;
	for(int i = l; i <= r; ++i) ans[i] = '*';
	for(L = l; a[L] == 1 && L <= r; ++L) ans[L] = '+';
	for(R = r; a[R] == 1 && R >= L; --R) ans[R] = '+';
	ans[R] = '+';
	//  1 
	
	int v = 1, flag = 0;
	for(int i = L; i <= R && !flag; ++i)
		if((v *= a[i]) >= 1e5) flag = 1;
	if(flag)
		for(int i = L; i < R; ++i) ans[i] = '*';
	else if(L <= R) {
		struct node { int l,r,val; };
		vector <node> c;
		vector <int> mul; //  
		c.push_back((node){0, 0, 1}), mul.push_back(1);
		for(int l0 = L,r0; l0 <= R; l0 = r0) {
			if(a[l0] == 1) {
				for(r0 = l0; r0 <= R && a[r0] == 1; ++r0);
				c.push_back((node){l0, r0 - 1, r0 - l0});
				mul.push_back(mul[(int)mul.size() - 1]);
			}
			else {
				int ml = 1;
				for(r0 = l0; r0 <= R && a[r0] > 1; ++r0) ml *= a[r0];
				c.push_back((node){l0, r0 - 1, ml});
				mul.push_back(mul[(int)mul.size() - 1] * ml);
			}
		} //
		vector <int> dp(c.size(), 0), pre(c.size(), 0);
		for(int i = 1; i < (int)c.size(); ++i) {
			dp[i] = dp[i - 1] + c[i].val;
			pre[i] = i - 1;
			for(int j = 0; j < i;  ++j)
				if(dp[i] < dp[j] + mul[i] / mul[j]) {
					dp[i] = dp[j] + mul[i] / mul[j];
					pre[i] = j;
				}
		}
		
		int nw = c.size() - 1;
		while(nw) {
			int l0 = c[nw].l, r0 = c[nw].r;
			ans[r0] = '+';
			if(a[l0] == 1)
				for(int i = l0; i < r0; ++i) ans[i] = '+';
			nw = pre[nw];
		}
	}
	
	for(int i = l; i <= r; ++i) printf("%d%c", a[i], i == n ? '\n' : ans[i]);
	return;
}

void solve3() {
	int l = 1, r;
	while(l <= n && a[l] == 0) printf("0%c", "+\n"[l++ == n]);
	for(; l <= n; l = r) {
		for(r = l; r <= n && a[r]; ++r);
		solve3_0range(l, r - 1);
		if(r <= n) printf("0%c", "+\n"[r++ == n]);
	}
} // +* & +-*

void solve() {
	if(opt == (opt & (-opt)) || opt == 3) solve1();
	if(opt == 6) solve2();
	if(opt == 5 || opt == 7) solve3();
}

int main() {
	input();
	solve();
	return 0;
}