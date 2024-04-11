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

const int MA = 300001, MX = MA + 5, mod = 998244353;
int n, x[MX], y[MX];
vi ini[MX], fin[MX];

struct ST {
	int dp[4 * MX][2][2], ini[4 * MX];
	
	void merge (int pos, int izq, int der) {
		forn (i, 2)
		forn (j, 2)
			dp[pos][i][j] = 0;
		
		forn (i, 2)
		forn (j, 2)
		forn (l, 2) {
			// Union
			if (j || ini[der])
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][1][l]) % mod;
			else
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][0][l]) % mod;
			
			// Interseccion
			if (j && ini[der])
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][1][l]) % mod;
			else
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][0][l]) % mod;
			
			// Excluyente
			if (j ^ ini[der])
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][1][l]) % mod;
			else
				dp[pos][i][l] = (dp[pos][i][l] + 1ll * dp[izq][i][j] * dp[der][0][l]) % mod;
		}
		
		ini[pos] = ini[izq];
	}
	
	void update (int i, int j, int pos, int a, int k) {
		if (a < i || j < a) return;
		
		if (i == j) {
			memset(dp[pos], 0, sizeof(dp[pos]));
			dp[pos][0][0] = 1;
			dp[pos][1][1] = 1;
			ini[pos] = k;
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		merge(pos, pos * 2, pos * 2 + 1);
	}
}st;

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		cin >> x[i] >> y[i];
		x[i]++, y[i]++;
		
		ini[x[i]].pb(i);
		fin[y[i] + 1].pb(i);
	}
	
	forr (i, 1, n)
		st.update(1, n, 1, i, 0);
	
	ll res = 0;
	forr (i, 1, MA) {
		for (int j : ini[i])
			st.update(1, n, 1, j, 1);
		
		for (int j : fin[i])
			st.update(1, n, 1, j, 0);
		
		if (x[1] <= i && i <= y[1])
			(res += st.dp[1][1][1]) %= mod;
		else
			(res += st.dp[1][0][1]) %= mod;
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