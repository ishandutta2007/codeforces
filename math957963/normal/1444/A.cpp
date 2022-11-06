#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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


int main() {
	int t;
	ll n,k, x, y, z, ans,nn;
	cin >> t;
	rep(tt, t) {
		cin >> n >> k;
      nn=n;
		ans = n;
		rep2(i, 2, N) {
			if ((i*i) > k)break;
			if (k%i == 0) {
                k/=i;
				x = 1;
				y = 1;
				while (k%i == 0) {
					x *= i;
					k /= i;
				}
				while (n%i == 0) {
					y *= i;
					n /= i;
				}
				if (x < y)z = y / x;
				else z = 1;
				ans = min(ans, z);
			}
		}
		if (k > 1) {
			x = 1;
			y = 1;
			while (n%k == 0) {
				y *= k;
				n /= k;
			}
			if (x < y)z = y / x;
			else z = 1;
			ans = min(ans, z);
		}
		ans = nn / ans;
		cout << ans << endl;
	}
	return 0;
}