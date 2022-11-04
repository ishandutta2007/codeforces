#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 300005;
int n;
ii a[MX];
ll s, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].se >> a[i].fi;
		s += a[i].se;
	}
	sort(a, a+n);
	s /= abs(s);

	for (int i = 0, j = 0; i < 62; i++) {
		ll acu = 0;

		while (j < n) {
			if (1ll << (i + 1) <= a[j].fi)
				break;
			if (__builtin_popcountll(res & a[j].fi) % 2)
				a[j].se *= -1;
			acu += a[j].se;
			j++;
		}

		if (!acu) continue;
		acu /= abs(acu);
		if (acu == s)
			res |= (1ll << i);
	}

	cout << res << endl;
 
	return 0;
}