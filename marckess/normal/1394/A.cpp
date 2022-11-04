#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, d, m;
vector<ll> a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> d >> m;

	forn (i, n) {
		ll in;
		cin >> in;
		if (in > m) a.pb(in);
		else b.pb(in);
	}

	sort(all(a), greater<ll>());
	sort(all(b), greater<ll>());

	ll acu = 0, res = 0;

	for (ll x : b) acu += x, res += x;

	for (int i = 0, j = (int)b.size() - 1; i < a.size(); i++) {
		acu += a[i];
		
		ll to = n - (i + 1) - i * d;
		if (to < 0) break;
		if ((i + 1) * d < int(a.size()) - (i + 1)) continue;

		while (j >= to) {
			acu -= b[j];
			j--;
		}

		res = max(res, acu);
	}

	cout << res << endl;

	return 0;
}