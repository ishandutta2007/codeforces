#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<18)
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
	int a[3000];
	vi ans;
	int t, n;
	int k, x;
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		v = true;
		rep(i, n) {
			cin >> a[i];
			if ((a[i] + i) % 2 == 0)v = false;
		}
		if (!v)cout << -1 << endl;
		else {
			ans.clear();
			for (int i = n; i >= 3; i -= 2) {
				rep(j, i) {
					if (a[j] == i) {
						ans.pb(j + 1);
						x = j / 2;
						rep(ii, x)swap(a[ii], a[j - ii]);
						break;
					}
				}
				rep(j, i) {
					if (a[j] == i - 1) {
						ans.pb(j);
						x = (j - 1) / 2;
						rep(ii, x)swap(a[ii], a[j - 1 - ii]);
						k = j + 2;
						break;
					}
				}
				ans.pb(k);
				x = (k - 1) / 2;
				rep(ii, x)swap(a[ii], a[k - 1 - ii]);
				ans.pb(3);
				swap(a[0], a[2]);
				ans.pb(i);
				x = (i - 1) / 2;
				rep(ii, x)swap(a[ii], a[i - 1 - ii]);
			}
			n = ans.size();
			cout << n << endl;
			if (n > 0) {
				rep(i, n - 1)cout << ans[i] << " ";
				cout << ans[n - 1] << endl;
			}
		}


	}



	return 0;
}