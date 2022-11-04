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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000000;
const ll inf = 1e18;
int k, q;
ll dp[6][MX], a[6];
deque<ii> dq;

void insert (ll x, int i) {
	while (dq.size() && dq.back().fi <= x)
		dq.pop_back();
	dq.emplace_back(x, i);
}

ll query (int i) {
	while (dq.front().se <= i - (3 * k - 2))
		dq.pop_front();
	return dq.front().fi;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k;
	forn (i, 6) cin >> a[i];
	
	forn (i, MX) dp[0][i] = -inf;
	
	forn (q, 3 * (k - 1) + 1) {
		int i = 3 * q;
		if (i >= MX) break;
		
		ll aux = q * a[0];
		
		forn (d, 10) {
			int x = i + d;
			if (x >= MX) break;
			
			ll off = d % 3 == 0 ? a[0] * d / 3 : 0;
			
			dp[0][x] = max(dp[0][x], aux + off);
		}
	}
	
	for (int j = 1, f = 30; j < 6; j++, f *= 10) {
		forn (i, MX) dp[j][i] = -inf;
		
		forn (r, f) {
			while (dq.size())
				dq.pop_back();
			
			for (int i = r, q = 0; i < MX; i += f, q++) {
				insert(dp[j - 1][i] - q * a[j], q);
				
				ll aux = query(q) + q * a[j];
				
				forn (d, 10) {
					int x = i + d * (f / 3);
					if (x >= MX) break;
					
					ll off = d % 3 == 0 ? a[j] * d / 3 : 0;
					
					dp[j][x] = max(dp[j][x], aux + off);
				}
			}
		}
	}
	
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cout << dp[5][n] << endl;
	}
	
	return 0;
}