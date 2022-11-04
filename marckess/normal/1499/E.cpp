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

const int MX = 1005, mod = 998244353;
int mem[MX][MX][3][4];
string s, t;

int dp (int i, int j, int f, int g) {
	if (i == s.size() && j == t.size())
		return g == 3;
	
	int &res = mem[i][j][f][g];
	if (res != -1) return res;
	res = g == 3;
	
	char ant = 0;
	if (f == 0) ant = s[i - 1];
	if (f == 1) ant = t[j - 1];
	
	if (i < s.size() && ant != s[i]) (res += dp(i + 1, j, 0, g | 1)) %= mod;
	if (j < t.size() && ant != t[j]) (res += dp(i, j + 1, 1, g | 2)) %= mod;
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> t;
	memset(mem, -1, sizeof(mem));
	
	ll res = 0;
	forn (i, s.size())
		forn (j, t.size())
			(res += dp(i, j, 2, 0)) %= mod;
	cout << res << endl;
	
	return 0;
}