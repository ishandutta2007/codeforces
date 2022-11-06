#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<18)
#define MOD 998244353
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
	int n, k;
	int ans, x, y, z;
	vector<int>a;
	cin >> n >> k;
	ans = 1;
	x = k;
	while (x < n) {
		x *= k;
		ans++;
	}
	cout << ans << endl;
	rep(i, n) {
		rep2(j, i+1, n - 1) {
			x = i;
			y = j;
			z = 1;
			while (true) {
				if ((x%k) < (y%k))break;
				z++;
				x /= k;
				y /= k;
			}
			a.pb(z);
		}
	}
	x = a.size();
	rep(i, x - 1)cout << a[i] << " ";
	cout << a[x - 1] << endl;
	return 0;
}