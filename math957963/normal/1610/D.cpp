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

vector<int>b;

bool check(void) {
	int n = b.size();
	rep(i, n) {
		if (b[i] != b[n - i - 1])return false;
	}
	return true;
}



int main() {
	ll n;
	ll p2[N];
	int c[100];
	int s[100];
	ll x, y, z, ans;
	p2[0] = (ll)1;
	rep(i, N - 1)p2[i + 1] = (p2[i] * 2) % MOD;
	rep(i, 100)c[i] = 0;
	cin >> n;
	rep(i, n) {
		cin >> x;
		rep(j, 100) {
			if (x % 2 == 1) {
				c[j]++;
				break;
			}
			x /= 2;
		}
	}
	s[99] = 0;
	for (int i = 98; i >= 0; i--) {
		s[i] = s[i + 1] + c[i];
	}
	ans = 0;
	x = (p2[c[0]] + MOD - 1) % MOD;
	x = (x*p2[s[1]]) % MOD;
	ans = (ans + x) % MOD;
	for (int i = 1; i < 99; i++) {
		if (c[i] > 0) {
			x = (p2[c[i] - 1] + MOD - 1) % MOD;
			x = (x*p2[s[i + 1]]);
			ans = (ans + x) % MOD;
		}
	}

	cout << ans << endl;
	return 0;
}