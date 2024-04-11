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
	ll n;
	ll k = 2050;
	ll a = 10;
	ll s;
	int t;
  cin>>t;
	rep(tt, t) {
		cin >> n;
		if (n%k != 0)cout << -1 << endl;
		else {
			s = 0;
			n /= k;
			while (n > 0) {
				s += (n%a);
				n /= a;
			}
			cout << s << endl;
		}
	}


	return 0;
}