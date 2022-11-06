// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;
int n;
ll a[MX], dp[MX];
stack<vi> st;

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	ll acu = 0;
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		ll s = i % 2 ? -dp[i + 1] : dp[i + 1];
		
		while (st.size() && st.top()[0] >= a[i]) {
			(acu -= st.top()[0] * st.top()[1]) %= mod;
			(s += st.top()[1]) %= mod;
			
			st.pop();
		}
		
		(acu += a[i] * s) %= mod;
		st.push({a[i], s});
		dp[i] = i % 2 ? -acu : acu;
	}
	
	cout << MOD(dp[0], mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}