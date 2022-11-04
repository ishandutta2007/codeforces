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

const int MX = 200005;
int n, m, k, a[MX], b[MX], t[MX], ind;
vii x, y, xy, inno;
multiset<int> si, no;
vi vr;

void solve () {
	cin >> n >> m >> k;
	
	forn (i, n) {
		cin >> t[i] >> a[i] >> b[i];
		
		if (a[i] && b[i]) xy.emplace_back(t[i], i);
		else if (a[i]) x.emplace_back(t[i], i);
		else if (b[i]) y.emplace_back(t[i], i);
		else no.insert(t[i]), inno.emplace_back(t[i], i);
	}

	sort(all(xy));
	sort(all(x));
	sort(all(y));

	ll sab = 0, sa = 0, sb = 0, ot = 0, res = 1e18;

	if (xy.size() + x.size() < k || xy.size() + y.size() < k) {
		cout << -1 << endl;
		return;
	}

	forn (i, xy.size()) sab += xy[i].fi;
	forn (i, x.size()) no.insert(x[i].fi);
	forn (i, y.size()) no.insert(y[i].fi);

	for (int i = xy.size(), j = 0, l = 0; i >= 0; i--) {
		while (j < x.size() && i + j < k) {
			sa += x[j].fi;
			
			if (si.count(x[j].fi)) {
				si.erase(si.find(x[j].fi));
				ot -= x[j].fi;
			} else {
				no.erase(no.find(x[j].fi));
			}

			j++;
		}

		while (l < y.size() && i + l < k) {
			sb += y[l].fi;

			if (si.count(y[l].fi)) {
				si.erase(si.find(y[l].fi));
				ot -= y[l].fi;
			} else {
				no.erase(no.find(y[l].fi));
			}

			l++;
		}

		while (no.size() && i + j + l + si.size() < m) {
			si.insert(*no.begin());
			ot += *no.begin();
			no.erase(no.begin());
		}

		while (si.size() && i + j + l + si.size() > m) {
			no.insert(*si.rbegin());
			ot -= *si.rbegin();
			si.erase(si.find(*si.rbegin()));
		}

		while (si.size() && no.size() && *si.rbegin() > *no.begin()) {
			ot -= *si.rbegin();
			ot += *no.begin();

			int aux = *si.rbegin();
			si.erase(si.find(aux));
			si.insert(*no.begin());

			no.erase(no.begin());
			no.insert(aux);
		}

		if (i + j >= k && i + l >= k && i + j + l + si.size() == m) {
			if (res > sab + sa + sb + ot) {
				res = sab + sa + sb + ot;
				ind = i;
			}
		}

		if (i) {
			no.insert(xy[i - 1].fi);
			sab -= xy[i - 1].fi;
		}
	}

	forn (i, xy.size()) {
		if (i < ind) vr.pb(xy[i].se);
		else inno.pb(xy[i]);
	}

	forn (i, x.size()) {
		if (i + ind + 1 <= k) vr.pb(x[i].se);
		else inno.pb(x[i]);
	}

	forn (i, y.size()) {
		if (i + ind + 1 <= k) vr.pb(y[i].se);
		else inno.pb(y[i]);
	}

	sort(all(inno));

	int faltan = m - int(vr.size());
	forn (i, faltan)
		vr.pb(inno[i].se);

	if (res == 1e18) cout << -1 << endl;
	else {
		cout << res << endl;
		for (int r : vr) cout << r + 1 << " ";
		cout << endl; 
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();	

	return 0;
}