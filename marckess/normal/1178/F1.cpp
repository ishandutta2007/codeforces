#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 505, mod = 998244353;
int n, c[MX];
ll mem[MX][MX];

ll dp (int a, int b) {
	if (a >= b) return 1;
	//cout << a <<" " << b << endl;
	
	if (mem[a][b] != -1)
		return mem[a][b];

	int mn = c[a], ind = a;
	for (int i = a; i <= b; i++)
		if (c[i] < mn) {
			mn = c[i];
			ind = i;
		}

	ll x = dp(a, ind - 1);
	for (int i = a; i < ind; i++)
		x += dp(a, i) * dp(i + 1, ind - 1) % mod;
	x %= mod;

	ll y = dp(ind + 1, b);
	for (int i = ind + 1; i <= b; i++)
		y += dp(ind + 1, i) * dp(i + 1, b) % mod;
	y %= mod;

	return mem[a][b] = x * y % mod;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	memset(mem, -1, sizeof(mem));
	cout << dp(0, n - 1) << endl;

	return 0;
}