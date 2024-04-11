#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
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
	ll k[N];
	ll r[N];
	bool u[30];
	char a[N];
	ll n, t;
	ll x, y, z;
	k[0] = (ll)1;
	rep(i, N - 1)k[i + 1] = (k[i] * (i + 1)) % MOD;
	x = MOD - 2;
	rep(i, 30) {
		if (x % 2 == 1)u[i] = true;
        else u[i]=false;
		x /= 2;
	}
	rep(i, N) {
		r[i] = (ll)1;
		x = k[i];
		rep(j, 30) {
			if (u[j])r[i] = (r[i] * x) % MOD;
			x = (x*x) % MOD;
		}
	}
	cin >> t;
	rep(i, N)a[i] = 0;
	rep(tt, t) {
		cin >> n;
		cin >> a;
		x = 0;
		y = 0;
		z = 0;
		rep(i, n) {
			if (a[i] == '0') {
				x++;
				z = 0;
			}
			else {
				z++;
				if (z % 2 == 0)y++;
			}
		}
     // cout<<x<<" "<<y<<endl;
		z = (k[x + y] * r[x]) % MOD;
		z = (z*r[y]) % MOD;
		cout << z << endl;
		rep(i, n + 1)a[i] = 0;
	}	
	return 0;
}