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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, h[MX], b[MX];
ll dp[MX], pre[MX];
set<ii> st, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> h[i];
	forn (i, n) cin >> b[i];
	
	dp[0] = b[0];
	pre[h[0]] = 0;
	st.emplace(h[0], b[0]);
	res.emplace(b[0], h[0]);
	
	for (int i = 1; i < n; i++) {
		ll mx = dp[i - 1];
		
		while (st.size() && h[i] < st.rbegin()->fi) {
			mx = max(mx, pre[st.rbegin()->fi]);
			res.erase(ii(st.rbegin()->se, st.rbegin()->fi));
			st.erase(*st.rbegin());
		}
		
		pre[h[i]] = mx;
		mx += b[i];
		
		st.emplace(h[i], mx);
		res.emplace(mx, h[i]);
		
		dp[i] = res.rbegin()->fi;
	}
	
	cout << dp[n - 1] << endl;
	
	return 0;
}