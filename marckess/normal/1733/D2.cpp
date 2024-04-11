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
int n;
ll x, y, mem[MX][MX][2];
string s, t;

ll dp (int i, int j, int f) {
	if (j < 0) return 1e18;
	
	if (i == n) {
		if (j || f) return 1e18;
		return 0;
	}
	
	ll &res = mem[i][j][f];
	if (res != -1) return res;
	res = dp(i + 1, j + f, s[i] != t[i]);
	
	// Hacer una operacion en i y avanzar
	// Operacion en i e i-1
	if (i >= 1)
		res = min(res, dp(i + 1, j + (1 - f), (s[i] != t[i]) ^ 1) + x);
	// Operacion en i y un j
	if (j >= 1)
		res = min(res, dp(i + 1, j - 1 + f, (s[i] != t[i]) ^ 1) + y);
	// Operacion en i y un i - 1 - j
	if (i - 1 - j >= 1)
		res = min(res, dp(i + 1, j + 1 + f, (s[i] != t[i]) ^ 1) + y);
	
	// Hacer dos operaciones en i
	// Operaciones en i y en dos j
	if (j >= 2)
		res = min(res, dp(i, j - 2, f) + 2 * y);
	// Operaciones en i, i-1 y un j
	if (j >= 1 && i >= 1)
		res = min(res, dp(i, j - 1, 1 - f) + x + y);
	
	return res;
}

void main_() {
	cin >> n >> x >> y >> s >> t;
	
	forn (i, n + 2)
	forn (j, n + 2)
		memset(mem[i][j], -1, sizeof(mem[i][j]));
	
	ll res = dp(0, 0, 0);
	if (res == 1e18) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(mem, -1, sizeof(mem));
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}