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

const int MX = 100005;
int n, a[MX];
vi res;
set<int> ex, st;

int sig (int i, set<int> &st) {
	auto it = st.upper_bound(i);
	if (it == st.end())
		it = st.begin();
	return *it;
}

bool valid (int i) {
	if (!ex.count(i)) return 0;
	int j = sig(i, ex);
	return __gcd(a[i], a[j]) == 1;
}

void solve () {
	cin >> n;
	
	res.clear();
	ex.clear();
	st.clear();

	forn (i, n) {
		cin >> a[i];
		ex.insert(i);
	}
	
	forn (i, n)
		if (valid(i))
			st.insert(i);
	
	int ind = 0;
	
	while (ex.size() && st.size()) {
		while (st.size()) {
			if (valid(ind)) {
				int j = sig(ind, ex);
				
				ex.erase(j);
				res.pb(j);
				st.erase(ind);
				
				if (valid(ind))
					st.insert(ind);
				ind = sig(ind, st);
				
				break;
			} else {
				st.erase(ind);
				ind = sig(ind, st);
			}
		}
	}
	
	cout << res.size();
	for (int r : res)
		cout << " " << r + 1;
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}