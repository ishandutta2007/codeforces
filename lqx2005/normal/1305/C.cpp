#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 2e5 + 10;
int t;
int cnt[N], a[N];
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i] % m]++;
	}
	for(int i = 0; i < m; i++) {
		if(cnt[i] > 1) {
			cout << 0 << endl;
			return;
		}
	}
	sort(a + 1, a + n + 1);
	int prod = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			prod = 1ll * prod * (a[j] - a[i]) % m;
		}
	}
	cout << prod << endl;
	return;
}

int main() {
	solve();
	return 0;
}