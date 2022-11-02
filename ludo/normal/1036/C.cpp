#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll binomcdf(int k, int nzs)
{
	ll ret = 0;
	if (nzs >= 0) ret++;
	if (nzs >= 1) ret += 9LL * k;
	if (nzs >= 2) ret += 81LL * k * (k - 1) / 2;
	if (nzs >= 3) ret += 9LL * 81LL * k * (k - 1) / 2 * (k - 2) / 3;
	return ret;
}

// # {y < x | P(y) }
ll F(ll x)
{
	ll ret = 0LL;

	int k = 0;
	for (ll y = 1; y <= x; y *= 10LL, k++) {
		int d = (x / y) % 10;

		int nz = 0;
		for (ll z = x / y; z /= 10;)
			nz += (z % 10) != 0;

		if (nz > 3) continue; // too much...

		if (d == 0) continue; // nothing smaller

		// try putting the digit 0 here.
		ret += binomcdf(k, 3 - nz);
		// try putting for all the digit 0 < d' < d to be put here.
		if (d > 1) ret += (d - 1) * binomcdf(k, 2 - nz);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		ll A, B;
		cin >> A >> B;
		ll ans = F(B + 1) - F(A);
		cout << ans << endl;
	}
	return 0;
}