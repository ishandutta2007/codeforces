#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int n;
	ll x, y, ans;
	vector<pll> a;
	cin >> n;
	ans = 0;
	rep(i, n) {
		cin >> x >> y;
		a.pb({ x,x + y });
		ans += y;
	}
	sort(all(a));
	y = a[0].second;
	rep2(i, 1, n - 1) {
		if (a[i].first > y)ans += (a[i].first - y);
		y = max(y, a[i].second);
	}
	cout << ans << endl;

	return 0;
}