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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, mem[MX][MX][30];
vii adj[MX];

int dp (int i, int j, int c) {
	int &res = mem[i][j][c];
	if (res != -1) return res;
	res = 0;

	for (ii &v : adj[i])
		if (v.se >= c)
			res |= 1 - dp(j, v.fi, v.se);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c - 'a');
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << "BA"[dp(i, j, 0)];
		cout << endl;
	}

	return 0;
}