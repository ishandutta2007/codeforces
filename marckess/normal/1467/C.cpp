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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n[3];
vi a[3];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, 3) cin >> n[i];
	forn (i, 3) {
		a[i] = vi(n[i]);
		forn (j, n[i])
			cin >> a[i][j];
		sort(all(a[i]));
	}
	
	ll res = -1e18;
	forn (i, 3) {
		ll p = 0;
		forn (l, n[i])
			p += a[i][l];
		
		forn (j, 3) if (i != j) {
			ll q = 0;
			
			forn (l, n[j])
				q -= a[j][l];
				
			forn (k, 3) if (k != i && k != j)
				forn (l, n[k])
					q += a[k][l];
			
			res = max(res, p + q);
		}
		
		ll o = 0;
		forn (j, 3) if (i != j) {
			forn (l, n[j]) {
				if (l) o += a[j][l];
				else o -= a[j][l];
			}
		}
		
		res = max(res, p + o);
	}
	
	cout << res << endl;
	
	return 0;
}