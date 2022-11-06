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
	int t, n;
	int od;
	int x, s;
	bool v = false;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		v = false;
		s = 0;
		rep(i, n) {
			cin >> x;
			s += x;
			if (x % 2 == 1)od = i;
		}
		x = 2;
		while ((x*x) <= s) {
			if (s%x == 0) {
				v = true;
				break;
			}
			x++;
		}
		if (v) {
			cout << n << endl;
			rep(i, n - 1)cout << i + 1 << " ";
			cout << n << endl;
		}
		else {
			x = 0;
			cout << n - 1 << endl;
			rep(i, n) {
				if (i != od) {
					x++;
					if (x < (n - 1))cout << i + 1 << " ";
					else cout << i + 1 << endl;
				}
			}
		}
	}



	return 0;
}