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

const int MX = 100005;
int n, q[MX];
ii a[MX], b[MX];
set<ii> st;
multiset<int> s, e;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return a[i] < a[j];
	});

	for (int _ = 0; _ < n; _++) {
		int i = q[_];

		while (st.size()) {
			if (st.begin()->fi >= a[i].fi) {
				break;
			}
			s.erase(s.find(b[st.begin()->se].fi));
			e.erase(e.find(b[st.begin()->se].se));
			st.erase(st.begin());
		}

		if (st.size()) {
			auto it = s.end();
			it--;

			if (*it > b[i].se) {
				cout << "NO" << endl;
				return 0;
			}

			it = e.begin();
			if (*it < b[i].fi) {
				cout << "NO" << endl;
				return 0;
			}
		}

		st.emplace(a[i].se, i);
		s.insert(b[i].fi);
		e.insert(b[i].se);
	}

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return b[i] < b[j];
	});

	st.clear(), e.clear(), s.clear();
	for (int _ = 0; _ < n; _++) {
		int i = q[_];

		while (st.size()) {
			if (st.begin()->fi >= b[i].fi) {
				break;
			}
			s.erase(s.find(a[st.begin()->se].fi));
			e.erase(e.find(a[st.begin()->se].se));
			st.erase(st.begin());
		}

		if (st.size()) {
			auto it = s.end();
			it--;

			if (*it > a[i].se) {
				cout << "NO" << endl;
				return 0;
			}

			it = e.begin();
			if (*it < a[i].fi) {
				cout << "NO" << endl;
				return 0;
			}
		}

		st.emplace(b[i].se, i);
		s.insert(a[i].fi);
		e.insert(a[i].se);
	}

	cout << "YES" << endl;

	return 0;
}