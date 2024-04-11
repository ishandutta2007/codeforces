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

const int MX = 1005;
string c, s, t;
int dp[1005][52][52], bs[52], bt[52];
int gos[52][27], got[52][27];
bool vis[1005][52][52];

void prekmp (int b[], string &p) {
	int i = 0, j = -1; b[0] = -1;
	while (i < p.size()) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

int go (int j, int c, int b[], int dp[52][27], string &s) {
	if (j < 0) return 0;
	if (dp[j][c] != -1) return dp[j][c]; 
	if (s[j] == c) return dp[j][c] = j + 1;
	return dp[j][c] = go(b[j], c, b, dp, s);
}

int obtRes (int i, int j, int k) {
	int f = 0;

	int &res = dp[i][j][k];
	if (vis[i][j][k]) return res;
	vis[i][j][k] = 1;

	if (j == s.size()) j = bs[j], f++;
	if (k == t.size()) k = bt[k], f--;
	if (i == c.size()) return res = f;

	res = -1e9;
	for (int l = 0; l < 26; l++)
		if (c[i] == '*' || c[i] == l) {
			int x = go(j, l, bs, gos, s);
			int y = go(k, l, bt, got, t);
			res = max(res, obtRes(i+1, x, y) + f); 
		}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	memset(gos, -1, sizeof(gos));
	memset(got, -1, sizeof(got));

	cin >> c >> s >> t;

	for (char &x : c) if (x != '*') x -= 'a';
	for (char &x : s) x -= 'a';
	for (char &x : t) x -= 'a';

	prekmp(bs, s);
	prekmp(bt, t);

	cout << obtRes(0, 0, 0) << endl;

	return 0;
}