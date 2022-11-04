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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, w, a[MX];
multiset<int> st;

void solve () {
	cin >> n >> w;
	forn (i, n) cin >> a[i];
	sort (a, a + n, greater<int>());
	
	st.clear();
	forn (i, n) {
		if (!st.size() || *st.rbegin() < a[i]) {
			st.insert(w - a[i]);
		} else {
			int x = *st.rbegin();
			st.erase(st.find(x));
			st.insert(x - a[i]);
		}
	}
	
	cout << st.size() << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)	
		solve();
	
	return 0;
}