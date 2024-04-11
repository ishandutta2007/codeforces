#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 10000
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
	int b[N];
	int x, y;
	vector<int>a[2];
	vector<pii>ans;
	cin >> n;
	cout << "? " << 1 << endl;
	cout.flush();
	rep(i, n) {
		cin >> b[i];
		if (b[i] % 2 == 0)a[0].pb(i);
		else a[1].pb(i);
	}
	x = a[0].size();
	y = a[1].size();
	if ((x - 1) <= y) {
		rep(i, n) {
			if (b[i] == 1)ans.pb({ 1,i + 1 });
		}
		rep(j, x-1) {
			cout << "? " << a[0][j + 1]+1 << endl;
			cout.flush();
			rep(i, n) {
				cin >> y;
				if (y == 1)ans.pb({ a[0][j + 1]+1,i + 1 });
			}
		}
	}
	else {
		rep(j, y) {
			cout << "? " << a[1][j]+1 << endl;
			cout.flush();
			rep(i, n) {
				cin >> x;
				if (x == 1)ans.pb({ a[1][j]+1,i + 1 });
			}
		}
	}
	cout << "!" << endl;
	cout.flush();
	rep(i, n - 1) {
		cout << ans[i].first << " " << ans[i].second << endl;
		cout.flush();
	}
	return 0;
}