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

const int MX = 2555;
int n;
ll res;
ii p[MX];

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator ^ (ii a, ii b) {
	return 1ll * a.fi * b.se - 1ll * a.se * b.fi;
}

int md (const ii &o, const ii &p, const ii &q) {
	ll f = (p - o) ^ (q - o);
	return f ? f / abs(f) : f;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].fi >> p[i].se;

	for (int i = 0; i < n; i++) {
		vii a;
		for (int j = 0; j < n; j++)
			if (i != j)
				a.pb(p[j]);

		sort(all(a), [&] (const ii &a, const ii &b) {
			if ((a < p[i]) != (b < p[i]))
				return b < p[i];
			return md(p[i], a, b) == 1;
		});

		for (int j = 0; j < n - 1; j++)
			a.pb(a[j]);

		for (int j = 0, k = 0; j < n - 1; j++, k = max(j, k)) {
			while (k + 1 - j <= n - 2 && md(p[i], a[j], a[k + 1]) == 1)
				k++;
			res += 1ll * (k - j) * (k - j - 1) * (k - j - 2) / 6;
		}
	}

	cout << 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24 - res << endl;

	return 0;
}