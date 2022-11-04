#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005, mod = 998244353;
int n, k, a[MX], b[MX], ex[MX];
list<int> l;
list<int>::iterator it[MX];

void solve () {
	while (l.size()) l.erase(l.begin());
	
	cin >> n >> k;
	
	forn (i, n) {
		cin >> a[i];
		l.pb(a[i]);
		it[a[i]] = l.end();
		it[a[i]]--;
		ex[a[i]] = 0;
	}
	
	forn (i, k) {
		cin >> b[i];
		ex[b[i]] = 1;
	}
	
	ll res = 1;
	
	forn (i, k) {
		auto tt = it[b[i]];
		int cn = 0;
		
		if (tt != l.begin()) {
			auto ot = tt;
			ot--;
			if (!ex[*ot]) cn++;
		}
		
		auto ot = tt;
		ot++;
		if (ot != l.end()) {
			if (!ex[*ot]) cn++;
		}
		
		(res *= cn) %= mod;
		if (!cn) break;
		
		ex[*tt] = 0;
		l.erase(tt);
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