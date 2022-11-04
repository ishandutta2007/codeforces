#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, a[MX], izq[MX], der[MX];
map<int, vi> mp;
set<int> st;

void solve () {
	mp.clear();
	st.clear();
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].pb(i);
	}
	
	izq[1] = a[1];
	for (int i = 2; i <= n; i++)
		izq[i] = max(izq[i - 1], a[i]);
	
	der[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		der[i] = max(der[i + 1], a[i]);
		
	for (const auto &it : mp) {
		const vi &v = it.se;
		
		for (int i = 1; i + 1 < v.size(); i++) {
			int l, r;
			
			auto jt = st.upper_bound(v[i]);
			if (jt != st.end()) r = *jt;
			else r = v.back();
			r = min(r, v.back());
			
			if (jt != st.begin()) {
				jt--;
				l = *jt;
			} else l = v[0];
			l = max(l, v[0]);
			
			if (izq[l] == it.fi && der[r] == it.fi) {
				cout << "YES" << endl << l << " " << r - 1 - l << " " << n - r + 1 << endl;
				return;
			}
		}
		
		for (int x : v)
			st.insert(x);
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