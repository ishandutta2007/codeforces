#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 100005;
int n;
ll a[MX], t[MX], x[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> t[i] >> x[i];
	t[n] = 1e18;
	
	ll i = 0, p = 0, to = 0, res = 0;
	
	while (i < n) {
		if (p == to)
			to = x[i];
			
		ll a = p, b = p;
		
		if (to < p) {
			a = p - ll(t[i + 1] - t[i]);
			a = max(a, to);
			p = a;
		}
		
		if (to > p) {
			b = p + ll(t[i + 1] - t[i]);
			b = min(b, to);
			p = b;
		}
		
		if (a <= x[i] && x[i] <= b)
			res++;
		
		i++;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
		
	return 0;
}