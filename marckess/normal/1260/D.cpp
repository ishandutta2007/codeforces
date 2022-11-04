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

const int MX = 200005;
int m, n, k, t, a[MX], l[MX], r[MX], d[MX];
vi pos[MX];

bool esPos (int m) {
	int acu = 0;

	for (int i = 1; i <= n;) {
		int to = 0;

		for (int j : pos[i])
			if (d[j] > m)
				to = max(to, r[j]);

		if (!to) {
			i++;
			continue;
		}

		while (i <= to) {
			for (int j : pos[i])
				if (d[j] > m)
					to = max(to, r[j]);

			acu += 2;
			i++;
		}
	}

	return (n + 1) + acu <= t;
}

void solve () {
	cin >> m >> n >> k >> t;

	forn (i, m) cin >> a[i];
	forn (i, k) {
		cin >> l[i] >> r[i] >> d[i];
		pos[l[i]].pb(i);
	}

	int i = 1, j = MX, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	int res = 0;
	forn (l, m)
		if (a[l] >= j)
			res++;
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	solve();	

	return 0;
}