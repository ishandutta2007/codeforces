#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef __int128 i128;
const int N = 2e5 + 10;
int n;
i64 w[N], h[N], t[N], s[N];
vector<i64> g[N];
int init(i64 a[], int n) {
	int tot = n;
	for(int i = 1; i <= n; i++) s[i] = a[i];
	sort(s + 1, s + tot + 1);
	tot = unique(s + 1, s + tot + 1) - (s + 1);
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(s + 1, s + tot + 1, a[i]) - s;
	}
	return tot;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> h[i] >> t[i];
	}
	int A = init(w, n), B = init(h, n);
	if(n != A * B) {
		cout << "0" << endl;
		return 0;
	}
	for(int i = 0; i <= A; i++) {
		g[i].resize(B + 1);
	}
	for(int i = 1; i <= n; i++) {
		g[w[i]][h[i]] += t[i];
	}
	for(int i = 2; i <= A; i++) {
		for(int j = 2; j <= B; j++) {
			if((i128)g[i - 1][j - 1] * g[i][j] != (i128)g[i - 1][j] * g[i][j - 1]) {
				cout << "0" << endl;
				return 0;
			}
		}
	}
	i64 T = 0;
	for(int i = 1; i <= A; i++) {
		for(int j = 1; j <= B; j++) {
			T = __gcd(T, g[i][j]);
		}
	}
	int ans = 0;
	for(int i = 1; 1ll * i * i <= T; i++) {
		if(T % i == 0) {
			ans++;
			if(1ll * i * i != T) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}