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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, a[MX], cn[MX], l[MX], r[MX];
vi res[MX], pos[MX], b4;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<int> inc, dec, mx, mn, no, noinc, nodec;
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	forn (i, q) {
		cin >> l[i] >> r[i];
		pos[l[i]].pb(i);
	}

	for (int i = n, x; i > 0; i--) {
		cn[i] = 2;

		#define upd(st,ns,c) while (st.size() && a[x = *st.begin()] c a[i]) { \
			ns.insert(x); \
			cn[x]--; \
			if (!cn[x]) no.insert(x); \
			st.erase(x); \
		}

		upd(inc, noinc, <)
		upd(dec, nodec, >)

		while (mx.size() && a[x = *mx.begin()] <= a[i]) mx.erase(x);
		while (mn.size() && a[x = *mn.begin()] >= a[i]) mn.erase(x);

		if (mx.size() && mn.size()) {
			auto it = no.lower_bound(max(*mx.begin(), *mn.begin()));
			if (it != no.end() && (b4.empty() || *it < b4.back())) {
				b4 = {i, *it};
				auto jt = inc.lower_bound(*it); jt--; b4.pb(*jt);
					 jt = dec.lower_bound(*it); jt--; b4.pb(*jt);
				sort(all(b4));
			}
		}

		for (int j : pos[i]) {
			if (b4.size() && b4.back() <= r[j]) res[j] = b4;
			else {
				#define b3(st,no) if (st.size()) { \
					auto it = no.lower_bound(*st.begin()); \
					if (it != no.end() && *it <= r[j]) res[j] = {i, *it - 1, *it}; \
				}

				b3(mx, noinc)
				b3(mn, nodec)
			}
		}

		inc.insert(i), dec.insert(i), mx.insert(i), mn.insert(i);
	}

	forn (i, q) {
		cout << res[i].size() << endl;
		for (int x : res[i])
			cout << x << " ";
		cout << endl;
	}

	return 0;
}