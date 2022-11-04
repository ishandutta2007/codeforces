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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, c, m;
ll dp[MX];

void main_() {
	cin >> n >> c;
	
	forn (i, MX)
		dp[i] = -1e9;
	
	forn (i, n) {
		 ll x, y, z;
		 cin >> x >> y >> z;
		 dp[x] = max(dp[x], y * z);
	}
	
	for (int i = MX - 1; i; i--) {
		if (dp[i] < 0) continue;
		for (ll x = 1, j = i; j < MX; j += i, x++)
			dp[j] = max(dp[j], x * dp[i]);
	}
	
	for (int i = 1; i < MX; i++)
		dp[i] = max(dp[i], dp[i - 1]);
	
	cin >> m;
	while (m--) {
		ll h, d;
		cin >> h >> d;
		
		if (h * d >= dp[c]) {
			cout << -1 << " ";
			continue;
		}
		
		int i = 1, j = c, rep = 20;
		while (rep--) {
			int m = (i + j) / 2;
			if (h * d < dp[m]) j = m;
			else i = m;
		}
		cout << j << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}