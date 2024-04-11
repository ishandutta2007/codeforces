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

const int MX = 200005, mod = 998244353;
int n, mem[MX][2][2][2][2][2][2];
string s;

int valid (int f, int g, int h) {
	return (f ^ g) >= (g ^ h) + (h ^ f);
}

int dp (int i, int a, int b, int c, int x, int y, int z) {
	if (i == n) return !x && !y && !z;
	
	int &res = mem[i][a][b][c][x][y][z];
	if (res != -1) return res;
	res = 0;
	
	forn (f, 2) if (!f || s[i] == '1' || !a)
	forn (g, 2) if (!g || s[i] == '1' || !b)
	forn (h, 2) if (!h || s[i] == '1' || !c) {
		int nx = x && valid(f, g, h);
		int ny = y && valid(g, h, f);
		int nz = z && valid(h, f, g);
		
		(res += dp(
			i + 1,
			a && ((s[i] == '1') == f),
			b && ((s[i] == '1') == g),
			c && ((s[i] == '1') == h),
			nx,
			ny,
			nz
		));
		if (res >= mod)
			res -= mod;
	}
	
	return res;
}

void main_() {
	cin >> s;
	n = s.size();
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 1, 1, 1, 1, 1, 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}