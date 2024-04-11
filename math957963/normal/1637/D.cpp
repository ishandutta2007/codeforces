#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 10010
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
	int t, n;
	int dp[N];
	int a[N];
	int b[N];
	int sa, sb, ss;
	int x, y;

	cin >> t;

	rep(tt, t) {
		rep(i, N)dp[i] = false;
		dp[0] = true;

		cin >> n;
		rep(i, n)cin >> a[i];
		rep(i, n)cin >> b[i];

		ss = 0;
		sa = 0;
		sb = 0;
		rep(i, n) {
			rep3(j, sa, sb) {
				if (dp[j]) {
					dp[j] = false;
					dp[j + a[i]] = true;
					dp[j + b[i]] = true;
				}
			}
			ss += (a[i] * a[i]) + (b[i] * b[i]);
			sa += max(a[i], b[i]);
			sb += min(a[i], b[i]);
		}
		x = (sa + sb + 1) / 2;
		rep2(i, x, sa) {
			if (dp[i]) {
				y = i;
				break;
			}
		}
		ss *= (n - 2);
		ss += (y*y) + ((sa + sb - y)*(sa + sb - y));
		cout << ss << endl;
	}
	return 0;
}