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

const int MX = 100005, Q = 100000;
int n, m, res[MX];
set<int, greater<int>> st;

ll techo (ll a, ll b) {
	return (a + b - 1) / b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	memset(res, -1, sizeof(res));
	st.insert(0);
	res[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		int t, y;
		ll x;
		cin >> t >> x >> y;
		
		set<int, greater<int>> in;
		
		for (ll k : st) {
			forn (kk, y) {
				if (t == 1)
					k += techo(x, Q);
				else
					k = techo(k * x, Q);
				
				if (k > m || res[k] != -1)
					break;
				
				res[k] = i;
				in.insert(k);
			}
		}
		
		for (int k : in)
			st.insert(k);
	}
	
	for (int i = 1; i <= m; i++)
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}