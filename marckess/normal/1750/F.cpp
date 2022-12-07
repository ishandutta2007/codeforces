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

const int MX = 5005;
int n, mod, mem[MX][2 * MX], dp[MX][MX];

ll dp2 (int i, int j) {
	if (i <= 0) return 0;
	
	int &res = mem[i][j + MX];
	if (res != -1) return res;
	
	return res = (dp[i][max(0, j)] + dp2(i - 1, j + 1)) % mod;
}

void main_() {
	cin >> n >> mod;
	
	memset(mem, -1, sizeof(mem));
	
	for (int i = 1; i <= n; i++) {
		ll acu = 1;
		
		for (int j = 0; j <= i; j++) {
			int x = j;
			
			int l = max(1, (i - 2 * x + 1) / 2);
			int r = i - x - 1;
			int k = (i - x - r) - x - 1;
			
			if (l <= r)
				(acu += dp[x][x] * (dp2(r, k) - dp2(l - 1, k + (r - l + 1)))) %= mod;
			
			dp[i][j] = acu;
		}
	}
	
	cout << MOD(dp[n][n], mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}