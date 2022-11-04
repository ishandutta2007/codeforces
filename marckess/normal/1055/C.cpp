#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll la, ra, ta;
ll lb, rb, tb;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;

	ll g = gcd(ta, tb);

	ll x = MOD(lb-la, g);
	ll d = min((ra-la+1)-x, rb-lb+1);
	ll res = max(0ll, d);

	ll y = MOD(la-lb, g);
	ll e = min((rb-lb+1)-y, ra-la+1);
	res = max(res, e);

	cout << res << endl;

	return 0;
}