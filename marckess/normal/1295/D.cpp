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

const int MX = 100005;
int bs[MX];
ll a, b;

void solve () {
	cin >> a >> b;

	ll d = __gcd(a, b);
	b /= d;
	ll res = b;

	for (ll i = 2; i * i <= b; i++) {
		if (bs[i]) continue;
		if (b % i == 0) res -= res / i;
		while (b % i == 0) b /= i;
	}

	if (b != 1) res -= res / b;
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}