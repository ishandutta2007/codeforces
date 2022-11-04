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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
vii v;

void solve () {
	cin >> n;
	v = vii(n);
	
	forn (i, n) cin >> v[i].fi;
	forn (i, n) cin >> v[i].se;
	sort(all(v));
	
	ll res = 0;
	ii act(1, 1);
	
	for (ii &p : v) {
		if (act == p) continue;
		
		if (act.fi + 1 == p.fi) {
			if ((act.fi + act.se) % 2 == 1 && act.se == p.se) res++;
			if ((act.fi + act.se) % 2 == 0 && act.se != p.se) res++;
		} else if (act.fi - act.se == p.fi - p.se) {
			if ((act.fi + act.se) % 2 == 0)
				res += p.fi - act.fi;
		} else {
			if ((act.fi + act.se) % 2 == 0)
				act.fi++;
			
			int d = min(p.fi - act.fi, p.se - act.se);
			act.fi += d;
			act.se += d;
			
			if (act.fi == p.fi) {
				if (act != p)
					res++;
			} else {
				d = p.fi - act.fi;
				res += (d + 1) / 2;
			}
		}
		
		act = p;
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