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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, k[MX], c[MX];

void solve () {
	cin >> n >> m;
	forn (i, n) cin >> k[i];
	sort (k, k + n);
	forn (i, m) cin >> c[i];
	
	ll res = 0;
	multiset<int> st;
	
	int j = 0;
	forn (i, n) {
		while (j < k[i]) {
			st.emplace(c[j]);
			j++;
		}
		
		res += c[k[i] - 1];
		
		if (st.empty()) continue;
		
		auto it = *st.begin();
		if (it - c[k[i] - 1] < 0) {
			res += it - c[k[i] - 1];
			st.emplace(c[k[i] - 1]);
			st.erase(st.find(it));
		}
	}
	
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