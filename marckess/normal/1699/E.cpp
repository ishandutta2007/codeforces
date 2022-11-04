// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5000005;
int n, m, a[MX], ex[MX], cn[MX];
ll dp[MX];

void main_() {
	cin >> n >> m;
	forr (i, 1, m) {
		ex[i] = cn[i] = 0;
		dp[i] = i;
	}
	
	int mx = m, mn = m;
	forn (i, n) {
		cin >> a[i];
		
		ex[a[i]] = 1;
		cn[dp[a[i]]] = 1;
		
		mn = min(mn, a[i]);
	}
	
	int res = mx - mn;
	
	for (ll i = m; i >= 1; i--) {
		if (i < mn)
			mn = i;
		
		for (ll p = i * i, q = i; p <= m; p += i, q++) {
			cn[dp[p]] -= ex[p];
			
			dp[p] = min(dp[p], max(i, dp[q]));
			
			cn[dp[p]] += ex[p];
		}
		
		while (!cn[mx] && mx > mn)
			mx--;
		
		res = min(res, mx - mn);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}