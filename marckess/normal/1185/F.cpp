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

const int MX = (1 << 9) + 5;
int n, m, a[MX], c[MX];
ii b[MX], d[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s, mk = 0;
		cin >> s;
		while (s--) {
			int x;
			cin >> x;
			mk |= 1 << (x - 1);
		}
		a[mk]++;
	}

	forn(i, MX) b[i] = ii(-1, -1);
	for (int i = 0; i < m; i++) {
		int s, p, mk = 0;
		cin >> p >> s;
		while (s--) {
			int x;
			cin >> x;
			mk |= 1 << (x - 1);
		}
		if (b[mk].fi == -1 || b[mk].fi > p)
			b[mk].fi = p, d[mk].fi = i + 1;
		else if (b[mk].se == -1 || b[mk].se > p)
			b[mk].se = p, d[mk].se = i + 1;
	}

	for (int i = (1 << 9) - 1; i >= 0; i--)
		for (int j = i; j; j = (j - 1) & i)
			c[i] += a[j];

	int mx = -1, mp = 0, ra, rb;
	for (int i = 0; i < (1 << 9); i++) {
		for (int j = i + 1; j < (1 << 9); j++) if (b[i].fi != -1 && b[j].fi != -1) {
			int s = c[i | j];
			if (s > mx || (s == mx && b[i].fi + b[j].fi < mp)) {
				mx = s;
				mp = b[i].fi + b[j].fi;
				ra = d[i].fi, rb = d[j].fi;
			}
		}

		if (b[i].se != -1)
			if (c[i] > mx || (c[i] == mx && b[i].fi + b[i].se < mp)) {
				mx = c[i];
				mp = b[i].fi + b[i].se;
				ra = d[i].fi, rb = d[i].se;
			}
	}

	cout << ra << " " << rb << endl;

	return 0;
}