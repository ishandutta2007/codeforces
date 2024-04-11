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

const int MX = 2005;
int n, a[MX], ex[MX];
vii res;
multiset<int> st;

bool go (int x) {
	res.clear();
	st.clear();
	
	forn (i, n)
		st.insert(a[i]);
	
	while (st.size()) {
		int mx = *st.rbegin();
		st.erase(st.find(mx));
		
		auto it = st.find(x - mx);
		if (it == st.end()) return 0;
		res.emplace_back(mx, *it);
		
		x = mx;
		st.erase(it);
	}
	
	return 1;
}

void solve () {
	cin >> n;
	n *= 2;
	
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	forn (i, n - 1) {
		int x = a[i] + a[n - 1];
		
		if (go(x)) {
			cout << "YES" << endl;
			cout << x << endl;
			for (ii &p : res)
				cout << p.fi << " " << p.se << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}