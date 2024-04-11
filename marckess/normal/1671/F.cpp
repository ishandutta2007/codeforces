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

const int mod = 998244353, SZ = 12;
int s[SZ + 1][SZ + 1][SZ + 1];
int mem1[1 << SZ][SZ + 1][SZ + 1][SZ + 1];
int mem2[2 * SZ + 1][2 * SZ + 1][SZ + 1][SZ + 1];

void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

int dp (int h, int i, int j, int k) {
	if (h < 0 || i < 0 || j < 0 || k < 0) return 0;
	if (h == 0 && i == 0 && j == 0 && k == 0) return 1;
	
	int &res = mem2[h][i][j][k];
	if (res != -1) return res;
	res = 0;
	
	forn (a, min(i, SZ) + 1) if (a > 1)
	forn (b, min(j, SZ) + 1)
	forn (c, min(k, SZ) + 1) {
		sum(res, 1ll * s[a][b][c] * dp(h - 1, i - a, j - b, k - c) % mod);
	}
	
	return res;
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}
ll inv[2 * SZ + 1];

ll ncr (ll n, ll r) {
	if (r < 0 || r > n) return 0;
	r = min(r, n - r);
	ll ans = 1;
	for (ll den = 1, num = n; den <= r; den++, num--)
		(ans *= num * inv[den] % mod) %= mod;
	return ans;
}

void main_() {
	int n, k, x;
	cin >> n >> k >> x;
	
	ll res = 0;
	forn (h, 2 * SZ + 1)
	forn (i, 2 * SZ + 1) {
		ll p = dp(h, i, k, x);
		if (p)
			(res += ncr(n - i + h, h) * p) %= mod;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (i, SZ)
		mem1[1 << i][i][0][0] = 1;
	
	forn (mk, (1 << SZ)) {
		if (!mk) continue;
		
		int cn = __builtin_popcount(mk);
		int f = mk == (1 << cn) - 1;
	
		forn (i, SZ)
		forn (j, SZ + 1)
		forn (k, SZ + 1) {
			if (f) {
				sum(s[cn][j][k], mem1[mk][i][j][k]);
			} else {
				forn (l, SZ) {
					if (mk & (1 << l)) continue;
					int d = __builtin_popcount(mk & ~((1 << l) - 1));
					
					if (j + d <= SZ) {
						sum(
							mem1[mk | (1 << l)][l][j + d][k + (i > l)],
							mem1[mk][i][j][k]
						);
					}
				}
			}
		}
	}
	
	memset(mem2, -1, sizeof(mem2));
	forn (i, 2 * SZ + 1)
		inv[i] = pot(i, mod - 2);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}