#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 410000
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
	int t, n;
	ll a[N];
	ll s, x;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i + 1];
		a[0] = 0;
		a[n + 1] = 0;
		a[n + 2] = 0;
		s = 0;
		rep(i, n + 1) {
			if ((a[i] < a[i + 1]) && (a[i + 1] > a[i + 2])) {
				x = max(a[i], a[i + 2]);
				s += (a[i + 1] - x);
				a[i + 1] = x;
				s += abs(a[i + 1] - a[i]);
			}
			else {
				s += abs(a[i + 1] - a[i]);
			}
		}
		cout << s << endl;
	}
	return 0;
}