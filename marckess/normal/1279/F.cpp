#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005, inf = 1e9;
int n, k, l, a[MX];
string s;
ii mem[MX];

ii operator + (ii a, ii b) {
	return {a.fi + b.fi, a.se + b.se};
}

ii & dp (int m) {
	forn(i, n+1) mem[i] = {inf, inf};
	mem[0] = {0, 0};
	forn(i, n) {
		mem[i + 1] = min(mem[i + 1], mem[i] + ii(a[i], 0));
		mem[min(i + l, n)] = min(mem[min(i + l, n)], mem[i] + ii(m, 1));
	}
	return mem[n];
}

int solve () {
	int i = 0, j = MX, rep = 22;
	while (rep--) {
		int m = (i + j) / 2;
		ii &r = dp(m);
		if (r.se <= k) j = m;
		else i = m;
	}
 	ii &r = dp(j);
	return r.fi - 1ll * j * k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> l >> s;
	
	forn (i, n) a[i] = 'a' <= s[i] && s[i] <= 'z';
	int res = solve();

	forn (i, n) a[i] = 1 - a[i];
	res = min(res, solve());

	cout << res << endl;

	return 0;
}