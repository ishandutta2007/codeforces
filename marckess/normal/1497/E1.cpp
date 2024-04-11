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

const int MX = 10000005;
int n, k, bs[MX];
set<vi> st;

void solve () {
	cin >> n >> k;
	st.clear();
	
	int res = 1;
	
	forn (i, n) {
		int a;
		cin >> a;
		vi v;
		
		while (a > 1) {
			int p = bs[a], pw = 0;
			while (a % p == 0) {
				a /= p;
				pw ^= 1;
			}
			if (pw) v.pb(p);
		}
		
		if (st.count(v)) {
			st.clear();
			res++;
		}
		st.insert(v);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}