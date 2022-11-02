#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll amod(ll x) { return (x %= mod) < 0 ? x + mod : x; }

ll F(ll x) {
	if (x == 0) return 0;
	ll ret = 0;

	ll numodd = 1, numeven = 2;
	ll nseen = 0, nxtlen = 1;
	bool par = 0;
	while (nseen + nxtlen <= x) {
		ll ct = par ? numeven : numodd;
		ll nm = nxtlen % mod;

		if (par) numeven = (numeven + 2 * nm) % mod;
		else numodd = (numodd + 2 * nm) % mod;

		ret = (ret + ct * nm) % mod;
		ret = (ret + nm * (nm-1)) % mod;

		nseen += nxtlen;
		nxtlen *= 2;
		par = par ^ 1;
	}

	ll ct = par ? numeven : numodd;
	ll nm = (x - nseen) % mod;

	ret = (ret + ct * nm) % mod;
	ret = (ret + nm * (nm-1)) % mod;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll L, R;
	cin >> L >> R;
	cout << amod(F(R) - F(L-1)) << endl;
	return 0;
}