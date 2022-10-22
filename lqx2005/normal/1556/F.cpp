#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
const int N = 14, M = 4782969, P = 1e9 + 7;
int n, a[N], p[N][N], q[N][1 << N], r[N][1 << N], L2[1 << N];
int dp[1 << N];

void Add(int &x, int y) {
	if((x += y) >= P && (x -= P));
} 

void Sub(int &x, int y) {
	if((x -= y) < 0 && (x += P));
}

int add(int x) {return x >= P ? x - P : x; }

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) 
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) L2[1 << i] = i;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j) {
				p[i][j] = 1ll * a[i] * power(a[i] + a[j], P - 2) % P;
			} else {
				p[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		q[i][0] = 1;
		r[i][0] = 1;
		for(int j = 1; j < (1 << n); j++) {
			int t = j & (-j);
			q[i][j] = 1ll * q[i][j ^ t] * p[i][L2[t]] % P;
			r[i][j] = 1ll * r[i][j ^ t] * p[L2[t]][i] % P;
		}
	}
	dp[0] = 1;
	for(int i = 1; i < (1 << n); i++) {
		dp[i] = 1;
		for(int s = (i - 1) & i;s ; s = (s - 1) & i) {
			int prod = 1;
			for(int j = 0; j < n; j++) {
				if(!(i >> j & 1)) continue;
				if(!(s >> j & 1)) {
					prod = 1ll * prod * q[j][s] % P;
				}
			}
			Sub(dp[i], 1ll * dp[s] * prod % P);
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		int cnt = 0, prod = 1;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) {
				cnt++;
			} else {
				prod = 1ll * prod * r[j][i] % P;
			}
		}
		Add(ans, 1ll * prod * dp[i] % P * cnt % P);
	}
	cout << ans << endl;
	return 0; 
}