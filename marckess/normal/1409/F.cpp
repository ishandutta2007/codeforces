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

const int MX = 205;
string s, t;
int n, k, mem[MX][MX][MX];

int dp (int i, int j, int k) {
	if (k < 0) return -1e9;
	if (i == s.size()) return 0;

	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = dp(i + 1, j, k);

	if (s[i] == t[0]) res = max(res, dp(i + 1, j + 1, k));
	if (s[i] == t[1]) res = max(res, dp(i + 1, j, k) + j);
	if (s[i] == t[0] && s[i] == t[1]) res = max(res, dp(i + 1, j + 1, k) + j);

	res = max(res, dp(i + 1, j + 1, k - 1) + j * (t[0] == t[1]));
	res = max(res, dp(i + 1, j + int(t[0] == t[1]), k - 1) + j);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s >> t;
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, k) << endl;

	return 0;
}