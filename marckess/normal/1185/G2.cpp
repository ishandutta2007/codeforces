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

const int mod = 1000000007;
int n, m, t[55], g[55], cn[3], mem2[55][55][55][4];
vector<vvi> mem[2505];

ll dp (int a, int b, int c, int f) {
	if (a + b + c == 0) return 1;
	int &res = mem2[a][b][c][f];
	if (res != -1) return res;
	res = 0;
	
	if (f && a) res += dp(a-1, b, c, 0) * ll(a) % mod;
	if (res >= mod) res -= mod;

	if (f - 1 && b) res += dp(a, b-1, c, 1) * ll(b) % mod;
	if (res >= mod) res -= mod;

	if (f - 2 && c) res += dp(a, b, c-1, 2) * ll(c) % mod;
	if (res >= mod) res -= mod;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) {
		cin >> t[i] >> g[i];
		cn[--g[i]]++;
	}

	for (int i = 0; i < 2505; i++)
		mem[i].assign(cn[0] + 1, vvi(cn[1] + 1, vi(cn[2] + 1, 0)));
	mem[0][0][0][0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = m - 1; j >= 0; j--) if (j + t[i] <= m)
			for (int a = 0; a <= cn[0] - (g[i] == 0); a++)
				for (int b = 0; b <= cn[1] - (g[i] == 1); b++)
					for (int c = 0; c <= cn[2] - (g[i] == 2); c++) {
						int &res = mem[j + t[i]][a + (g[i] == 0)][b + (g[i] == 1)][c + (g[i] == 2)];
						res += mem[j][a][b][c];
						if (res >= mod) res -= mod;
					}

	memset(mem2, -1, sizeof(mem2));
	int res = 0;
	for (int a = 0; a <= cn[0]; a++)
		for (int b = 0; b <= cn[1]; b++)
			for (int c = 0; c <= cn[2]; c++) {
				res += mem[m][a][b][c] * dp(a, b, c, 3) % mod;
				if (res >= mod) res -= mod;
			}
	cout << res << endl;

	return 0;
}