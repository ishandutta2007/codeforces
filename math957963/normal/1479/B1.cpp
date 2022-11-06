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
	vi a[N];
	int x;
	int c;
	int sz;
	int ans = 0;
	cin >> n;
	rep(i, n) {
		cin >> x;
		a[x - 1].pb(i);
	}
	rep(i, N) {
		sz = a[i].size();
		if (sz > 0) {
			ans++;
			c = 1;
			rep2(j, 1, sz - 1) {
				if (a[i][j] - a[i][j - 1] > 2)c = max(0, c - 2);
				else if (a[i][j] - a[i][j - 1] == 2)c = max(0, c - 1);
				if (c < 2) {
					ans++;
					c++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}