
// Problem : G. Minimal Coverage
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/G
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 10005, lim = 2000;
int n, a[MX], mem[MX][lim + 1], vis[MX][lim + 1], col;

int dp (int i, int j) {
	if (j < 0 || j > lim) return 1e9;
	if (i == n) return j;
	
	int &res = mem[i][j];
	if (vis[i][j] == col) return res;
	vis[i][j] = col;
	
	return res = max(j, min(dp(i + 1, j + a[i]), dp(i + 1, j - a[i])));
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	int res = 1e9;
	
	col++;
	forn (j, lim + 1)
		res = min(res, dp(0, j));
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}