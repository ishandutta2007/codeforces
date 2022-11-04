#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
int n, op, cl, qu;
string s;
ll fac[MX], inv[MX], res;
vi acu[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void calc (int n) {
	if (acu[n].size()) return;

	acu[n].resize(n + 1);
	acu[n][0] = 1;

	for (int i = 1; i <= n; i++) {
		acu[n][i] = acu[n][i-1] + comb(n, i);
		if (acu[n][i] >= mod) acu[n][i] -= mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i-1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> s;
	n = s.size();

	for (char c : s) {
		if (c == '(') op++;
		else if (c == ')') cl++;
		else qu++;
	}

	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') x++;
		else if (s[i] == ')') y++;
		else z++;

		if (s[i] == '(') {
			calc(qu);

			int t = (qu - z) + (cl - y) - x;
			if (t >= 0) {
				res += acu[qu][min(qu, t)];
				if (res >= mod) res -= mod;
			}
		} else if (s[i] == '?') {
			calc(qu - 1);

			int t = (qu - z) + (cl - y) - x - 1;
			if (t >= 0) {
				res += acu[qu - 1][min(qu - 1, t)];
				if (res >= mod) res -= mod;
			}
		}
	}
	cout << res << endl;

	return 0;
}