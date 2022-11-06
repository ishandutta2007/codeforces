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
	int x, y, ans;
	int a[N];
	int b[N];
	bool used[N];
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> b[i];
		rep(i, n) {
			cin >> x;
			a[b[i] - 1] = x - 1;
			used[i] = false;
		}
		ans = 1;
		rep(i, n) {
			if (!used[i]) {
				ans = (ans * 2) % MOD;
				x = i;
				while (!used[x]) {
					used[x] = true;
					x = a[x];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}