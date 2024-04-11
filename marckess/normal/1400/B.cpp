#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int p, f, cs, cw, s, w, res;

void go () {
	for (int i = min(cs, p / s); i >= 0; i--) {
		int acu = i;
		int as = cs - i;
		int aw = cw;

		int d = min(aw, (p - i * s) / w);
		acu += d;
		aw -= d;

		d = min(as, f / s);
		acu += d;

		d = min(aw, (f - d * s) / w);
		acu += d;

		res = max(res, acu);
	}
}

void solve () {
	cin >> p >> f >> cs >> cw >> s >> w;
	res = 0;

	if (s > w) {
		swap(s, w);
		swap(cs, cw);
	}

	go();
	swap(p, f);
	go();

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