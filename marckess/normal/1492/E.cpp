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

const int MX = 250005;
int n, m;
vi s[MX];

int dif (vi &a, vi &b) {
	int cn = 0;
	forn (j, m)
		cn += a[j] != b[j];
	return cn;
}

ii go (vi &v) {
	ii res;
	forn (i, n)
		res = max(res, ii(dif(s[i], v), i));
	return res;
}

void ans (vi &v) {
	cout << "Yes" << endl;
	forn (j, m)
		cout << v[j] << " ";
	cout << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) {
		s[i].resize(m);
		forn (j, m)
			cin >> s[i][j];
	}
	
	ii p = go(s[0]);
	
	if (p.fi <= 2) ans(s[0]);
	
	if (p.fi > 4) {
		cout << "No" << endl;
		return 0;
	}
	
	vi d;
	forn (j, m)
		if (s[0][j] != s[p.se][j])
			d.pb(j);
	
	forn (x, d.size()) {
		vi v = s[0];
		v[d[x]] = s[p.se][d[x]];
		
		ii q = go(v);
		if (q.fi <= 2) ans(v);
		else if (q.fi == 3) {
			forn (j, m)
				if (v[j] != s[q.se][j]) {
					vi w = v;
					w[j] = s[q.se][j];
					
					if (go(w).fi <= 2) ans(w);
				}
		}
	}
	
	forn (x, d.size()) forn (y, x) {
		vi v = s[0];
		v[d[x]] = s[p.se][d[x]];
		v[d[y]] = s[p.se][d[y]];
		
		if (go(v).fi <= 2) ans(v);
	}
	
	cout << "No" << endl;
	
	return 0;
}