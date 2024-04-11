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

const int MX = 400005, mod = 1000000007;
int n, a[MX], b[MX], p[MX], vis[MX];

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		p[b[i]] = a[i];
		vis[i] = 0;
	}
	
	ll cn = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int u = i;
			cn++;
			
			do {
				vis[u] = 1;
				u = p[u];
			} while (u != i);
		}
	
	ll res = 1;
	while (cn--)
		(res *= 2) %= mod;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}