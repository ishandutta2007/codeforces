#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007
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
	int a[N];
	int b[N];
	int l, r, m, x;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i] >> b[i];
		l = 1;
		r = n + 1;
		while ((r - l) > 1) {
			m = (l + r) / 2;
			m--;
			x = 0;
			rep(i, n) {
				if ((a[i] >= (m - x)) && (b[i] >= x))x++;
				if (x > m)break;
			}
			m++;
			if (x >= m)l = m;
			else r = m;
		}
		cout << l << endl;
	}

	return 0;
}