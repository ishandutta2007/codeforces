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
	int n, m;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(1, 1000000);
	char a[1010];
	int c[1010];
	long double p2[10100];
	long double p = 0.8;
	p2[0] = 1000000.000;
	rep(i, 10098)p2[i + 1] = p2[i] * p;
	int ans;
	int mn = 0;
	int x;
	long double c0, c1, cc;
	rep(i, 1010) {
		a[i] = 0;
		c[i] = 0;
	}
	cin >> n >> m;
	rep(i, m) {
		cin >> a;
		c0 = 0;
		c1 = 0;
		rep(i, n) {
			if (a[i] == '0')c0 += p2[c[i] - mn];
			else c1 += p2[c[i] - mn];
		}
		x = rand(mt);
		cc = (long double)x;
		cc = cc / ((long double)1000000.00);
		cc = cc * (c0 + c1);
		if (cc < c0)cout << 0 << endl;
		else cout << 1 << endl;
		cout.flush();
		cin >> ans;
		mn = MOD;
		rep(i, n) {
			if (a[i] != ('0' + ans))c[i]++;
			mn = min(mn, c[i]);
		}
		rep(i, n + 1)a[i] = 0;
	}

	return 0;
}