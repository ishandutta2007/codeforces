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

const int mod = 1000000007;
ll b, q, y;
ll c, r, z;

int solve (ll p) {
	if (p * q / __gcd(p, q) != r) return 0;
	
	if ((c - b) % q) return 0;
	
	ll bb = b + (y - 1) * q;
	ll cc = c + (z - 1) * r;
	if (c < b || bb < cc) return 0;
	
	if (c - r < b) return -1;
	if (cc + r > bb) return -1;
		
	return 1ll * (r / p) * (r / p) % mod;
}

void main_() {
	cin >> b >> q >> y;
	cin >> c >> r >> z;
	
	int res = 0;
	for (int p = 1; p * p <= r; p++)
		if (r % p == 0) {
			int d = solve(p);
			if (d == -1) {
				cout << -1 << endl;
				return;
			}
			(res += d) %= mod;
			
			if (p * p != r) {
				d = solve(r / p);
				if (d == -1) {
					cout << -1 << endl;
					return;
				}
				(res += d) %= mod;
			}
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