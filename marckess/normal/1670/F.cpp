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
int n;
ll l, r, z;
int memc[1005][1005], mem[60][2005];

int comb (int n, int k) {
	if (k == n || k == 0) return 1;
	
	int &res = memc[n][k];
	if (res != -1) return res;
	
	return res = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod;
}

ll x;
int dp (int i, int j) {
	if (i == -1) return 1;
	
	j = min(j, 2 * n);
	
	int &res = mem[i][j];
	if (res != -1) return res;
	res = 0;
	
	if (x & (1ll << i))
		if (j < 2 * n)
			j++;
	
	for (int k = bool(z & (1ll << i)); k <= min(n, j); k += 2)
		res = (res + 1ll * comb(n, k) * dp(i - 1, 2 * (j - k))) % mod;
	
	return res;
}

int f (ll xx) {
	memset(mem, -1, sizeof(mem));
	x = xx;
	return dp(59, 0);
}

void main_() {
	cin >> n >> l >> r >> z;
	cout << MOD(f(r) - f(l - 1), mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(memc, -1, sizeof(memc));
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}