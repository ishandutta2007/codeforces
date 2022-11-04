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

string s, t, cs, ct;
vi vs, vt;
void solve () {
	cin >> s >> t;
	
	cs.clear(), ct.clear(), vs.clear(), vt.clear();
	for (int c : s) {
		if (cs.empty() || c != cs.back()) {
			cs.pb(c), vs.pb(1);
		} else {
			vs.back()++;
		}
	}
	for (int c : t) {
		if (ct.empty() || c != ct.back()) {
			ct.pb(c), vt.pb(1);
		} else {
			vt.back()++;
		}
	}

	if (vs.size() != vt.size()) {
		cout << "NO" << endl;
	} else {
		for (int i = 0; i < vs.size(); i++)
			if (cs[i] != ct[i] || vs[i] > vt[i]) {
				cout << "NO" << endl;
				return;
			}
		cout << "YES" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}