#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100000;
vector<ll> v;
ll m;

ii obtRes (ll n) {
	if (n < 8) return {n, n};

	int x = find(v, n+1)-1;
	ii a = obtRes(n - v[x]);
	ii b = obtRes(v[x] - 1 - v[x-1]);

	if (a.fi > b.fi || (a.fi == b.fi && a.se + v[x] > b.se + v[x-1]))
		return {a.fi + 1, a.se + v[x]};
	return {b.fi + 1, b.se + v[x-1]};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (ll i = 1; i <= MX; i++)
		v.push_back(i*i*i);

	cin >> m;
	ii res = obtRes(m);
	cout << res.fi << " " << res.se << endl;

	return 0;
}