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

const int MX = 505;
int n, l, r, s;

void solve () {
	cin >> n >> l >> r >> s;
	
	vi v;
	for (int i = 1; i <= (r - l + 1); i++) {
		v.pb(i);
		s -= i;
	}
	
	if (s < 0) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		int up = i + 1 == (int)v.size() ? n : v[i + 1] - 1;
		int d = min(up - v[i], s);
		s -= d;
		v[i] += d;
	}
	
	if (s) {
		cout << -1 << endl;
		return;
	}
	
	set<int> st;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	
	for (int x : v)
		st.erase(x);
	
	for (int i = 1; i <= n; i++) {
		if (l <= i && i <= r) cout << v[i - l] << " ";
		else {
			cout << *st.begin() << " ";
			st.erase(st.begin());
		}
	}
	
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