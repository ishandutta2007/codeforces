#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ii a[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> a[i].se >> a[i].fi;
	sort (a, a + n);
	
	ll res = 0, acu = 0;
	int i = 0, j = n - 1;
	
	while (i <= j) {
		if (acu >= a[i].fi) {
			ll d = a[i].se;
			a[i].se -= d;
			res += d;
			acu += d;
			
			i++;
		} else {
			ll d = min(a[i].fi - acu, a[j].se);
			a[j].se -= d;
			res += 2 * d;
			acu += d;
			
			if (!a[j].se)
				j--;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}