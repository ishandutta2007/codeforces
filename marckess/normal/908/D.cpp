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
 
const int mod = 1000000007;
int k;
ll pa, pb, mem[1005][1005];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll dp (int i, int a) {
	if (i >= k) return i;
	if (a >= k) {
		return pb * ((a + i - 1) * pot(1 - pa, mod - 2) % mod + pot((1 - pa) * (1 - pa) % mod, mod - 2)) % mod;
	}
	ll &res = mem[i][a];
	if (res != -1) return res;
	return res = (pa * dp(i, a + 1) + pb * dp(i + a, a)) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> pa >> pb;
	ll aux = pa;
	pa = pa * pot(pa + pb, mod - 2) % mod;
	pb = pb * pot(aux + pb, mod - 2) % mod;

	memset(mem, -1, sizeof(mem));
	ll res = pa * dp(0, 1) % mod * pot(1 - pb, mod - 2);
	cout << MOD(res, mod) << endl;
 
	return 0;
}