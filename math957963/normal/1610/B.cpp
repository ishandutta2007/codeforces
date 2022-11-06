#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
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

vector<int>b;

bool check(void) {
	int n = b.size();
	rep(i, n) {
		if (b[i] != b[n - i - 1])return false;
	}
	return true;
}



int main() {
	int t;
	int n;
	int a[N];
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i];
		v = true;
		rep(i, n) {
			if (a[i] != a[n - i - 1]) {
				b.clear();
				rep(j, n) {
					if (a[j] != a[i])b.pb(a[j]);
				}
				v = check();
				if (v)break;
				b.clear();
				rep(j, n) {
					if (a[j] != a[n - i - 1])b.pb(a[j]);
				}
				v = check();
				break;
			}
		}
		if (v)cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}