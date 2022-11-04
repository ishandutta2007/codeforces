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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = (1 << 20) + 5;
int n, m, adj[22][22];
string s;
ll mem[MX];

ll dp (int mk, int s) {
	if (mk == (1 << m) - 1)
		return 0;

	ll &res = mem[mk];
	if (res != -1) return res;
	res = 1e18;

	for (int i = 0; i < m; i++)
		if (!(mk & (1 << i))) {
			int t = 0;

			for (int j = 0; j < m; j++)
				if (i != j) {
					if (mk & (1 << j))
						t -= adj[i][j];
					else
						t += adj[i][j];
				}

			res = min(res, dp(mk | (1 << i), s + t) + (s + t));
		}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> s;
	for (char &c : s)
		c -= 'a';

	for (int i = 0; i + 1 < n; i++) {
		adj[s[i]][s[i+1]]++;
		adj[s[i+1]][s[i]]++;
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;

	return 0;
}