#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, q, dp[255][255][255], sz[3], i, sig[100005][26];
string s, a[3];
char op, h;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> s;

	memset(sig, -1, sizeof(sig));

	for (char &c : s)
		c -= 'a';

	for (int i = 0; i < 26; i++)
		sig[n][i] = n;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++)
			sig[i][j] = sig[i+1][j];
		sig[i][s[i]] = i;
	}

	dp[0][0][0] = -1;
	while (q--) {
		cin >> op >> i;
		i--;

		if (op == '-') {
			a[i].pop_back();
			sz[i]--;
		} else {
			cin >> h;
			a[i].pb(h-'a');
			sz[i]++;

			for (int x = (i == 0 ? sz[0] : 0); x <= sz[0]; x++)
				for (int y = (i == 1 ? sz[1] : 0); y <= sz[1]; y++)
					for (int z = (i == 2 ? sz[2] : 0); z <= sz[2]; z++) {
						dp[x][y][z] = n;
						if (x && dp[x-1][y][z] < n) dp[x][y][z] = min(dp[x][y][z], sig[dp[x-1][y][z]+1][a[0][x-1]]);
						if (y && dp[x][y-1][z] < n) dp[x][y][z] = min(dp[x][y][z], sig[dp[x][y-1][z]+1][a[1][y-1]]);
						if (z && dp[x][y][z-1] < n) dp[x][y][z] = min(dp[x][y][z], sig[dp[x][y][z-1]+1][a[2][z-1]]);
					}
		}
		if (dp[sz[0]][sz[1]][sz[2]] < n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}