#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, mem[MX][MX][2][2];
int vis[MX][MX][2][2];
string s;

int dp (int x, int y, int f, int g) {
	if (!x && !y && !f) return 0;
	
	int &res = mem[x][y][f][g];
	if (vis[x][y][f][g]) return res;
	
	vis[x][y][f][g] = 1;
	res = 1e9;
	
	if (x) res = min(res, 1 - dp(x - 1, y + 1, f, 0));
	if (y) res = min(res, 1 - dp(x, y - 1, f, 0));
	if (f) res = min(res, 1 - dp(x, y, f - 1, 0));
	
	if (!g && y) res = min(res, 0 - dp(x, y, f, 1));
	
	return res;
}

void solve () {
	cin >> n >> s;
	
	int i = 0, j = n - 1;
	int x = 0, y = 0, f = 0;
	
	while (i < j) {
		if (s[i] != s[j])
			y++;
		else if (s[i] == '0')
			x++;
		i++, j--;
	}
	
	if (n % 2 && s[n / 2] == '0')
		f = 1;
	
	if (dp(x, y, f, 0) > 0) cout << "BOB" << endl;
	else if (dp(x, y, f, 0) == 0) cout << "DRAW" << endl;
	else cout << "ALICE" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}