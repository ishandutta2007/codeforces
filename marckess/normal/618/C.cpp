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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ii p[MX];

ll dis (ii a, ii b) {
	return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator ^ (ii a, ii b) {
	return a.fi * b.se - a.se * b.fi;
}

int md (ii o, ii p, ii q) {
	ll r = (p - o) ^ (q - o);
	if (!r) return r;
	return r / abs(r);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].fi >> p[i].se;

	int a = 1, b = 2, c = -1;

	for (int i = 1; i <= n; i++) {
		if (a != i && dis(p[a], p[i]) < dis(p[a], p[b])) {
			b = i;
		}
	}

	for (int i = 1; i <= n; i++)
		if (i != a && i != b) {
			if (c == -1) {
				if (md(p[a], p[b], p[i])) {
					c = i;
				}
				continue;
			}

			int f = md(p[a], p[b], p[i]);
			if (!f) continue;

			int g = md(p[b], p[c], p[i]);
			if (!g && (dis(p[b], p[i]) < dis(p[b], p[c]) && dis(p[c], p[i]) < dis(p[b], p[c]))) {
				c = i;
				continue;
			}
			if (g != f) continue;

			g = md(p[c], p[a], p[i]);
			if (!g || (dis(p[c], p[i]) < dis(p[a], p[c]) && dis(p[a], p[i]) < dis(p[a], p[b]))) {
				c = i;
				continue;
			}
			if (g != f) continue;

			c = i;
		}

	cout << a << " " << b << " " << c << endl;

	return 0;
}