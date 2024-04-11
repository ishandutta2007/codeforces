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

const int MX = 100005, mod = 1000000007;
int n, dp[MX];
vi divi[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void main_() {
	cin >> n;
	
	forr (i, 1, MX - 1)
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	
	forr (i, 1, MX - 1) {
		dp[i] = i - 1;
		for (int d : divi[i])
			if (d != i)
				dp[i] -= dp[d];
	}
	
	ll res = 0;
	forr (c, 1, n - 2) {
		for (int d : divi[n - c]) {
			ll cn = dp[(n - c) / d];
			(res += cn * d % mod * c % mod * pot(__gcd(d, c), mod - 2)) %= mod;
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}