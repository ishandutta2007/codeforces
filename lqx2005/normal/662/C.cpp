#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define sz(a) int((a).size())
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
const int N = 20, M = 1e5 + 10, P = 998244353;
int n, m;
int f[1 << N], g[1 << N];
char s[N][M];
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P;
	return c;
}
void FWT(int f[], int n, int t) {
	for(int i = 2; i <= 1 << n; i <<= 1) {
		for(int j = 0; j < 1 << n; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				int x = f[j + k], y = f[j + k + (i >> 1)];
				f[j + k] = (x + y) % P, f[j + k + (i >> 1)] = (x - y + P) % P;
			}
		}
	}
	if(t == -1) {
		int inv = power(2, P - 1 - n);
		for(int i = 0; i < 1 << n; i++) f[i] = 1ll * f[i] * inv % P;
	}
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> (s[i] + 1);
	}
	for(int i = 1; i <= m; i++) {
		int mask = 0;
		for(int j = n - 1; j >= 0; j--) mask = (mask << 1) | (s[j][i] - '0');
		f[mask]++;
	}
	for(int i = 1; i < 1 << n; i++) g[i] = g[i >> 1] + (i & 1);
	for(int i = 0; i < 1 << n; i++) g[i] = min(g[i], n - g[i]);
	FWT(f, n, 1), FWT(g, n, 1);
	for(int i = 0; i < 1 << n; i++) f[i] = 1ll * f[i] * g[i] % P;
	FWT(f, n, -1);
	int ans = m * n;
	for(int i = 0; i < 1 << n; i++) ans = min(ans, f[i]);
	cout << ans << endl;
	return 0;
}