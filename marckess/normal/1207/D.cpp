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

const int mod = 998244353, MX = 300005;
int n;
ll f[MX], in[MX], r = 1, s = 1, t = 1;
map<int, int> a, b;
map<ii, int> p;
ii q[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	f[0] = 1;
	for (int i = 1; i < MX; i++)
		f[i] = f[i-1] * i % mod;

	cin >> n;
	forn(i, n) {
		cin >> q[i].fi >> q[i].se;
		a[q[i].fi]++, b[q[i].se]++;
		p[ii(q[i].fi, q[i].se)]++;
		(r *= a[q[i].fi]) %= mod;
		(s *= b[q[i].se]) %= mod;
		(t *= p[ii(q[i].fi, q[i].se)]) %= mod;
	}

	sort(q, q+n);
	for (int i = 1; i < n; i++)
		if (q[i-1].se > q[i].se)
			t = 0;
	cout << MOD(f[n] - r - s + t, mod) << endl;

	return 0;
}