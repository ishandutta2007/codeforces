#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define N 3000
#define MOD 998244353



int main() {
	int n;
	int m;
	int a[N];
	int b[N];
	int c[N];
	int d[N];
	int ans, x;
	vector<pii>e;
	cin >> n >> m;
	rep(i, n)cin >> a[i] >> b[i];
	rep(i, m)cin >> c[i] >> d[i];
	rep(i, n) {
		rep(j, m) {
			e.push_back({ max(0,c[j] - a[i]+1),max(0,d[j] - b[i]+1) });
		}
	}
	sort(all(e), greater<pii>());
	ans = e[0].first;
	x = 0;
	rep(i, n*m) {
		ans = min(ans, x + e[i].first);
		x = max(x, e[i].second);
	}
    ans = min(ans, x);
	cout << ans << endl;
	return 0;
}