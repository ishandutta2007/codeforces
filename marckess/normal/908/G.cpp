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

const int MX = 705, mod = 1000000007;
int d;
string s;
ll p[MX], cn[MX][MX][2], sum[MX][MX][2];

void dp (int i, int j, int f) {
	if (i == s.size()) {
		sum[i][j][f] = 0;
		cn[i][j][f] = 1;
		return;
	}

	if (cn[i][j][f] != -1)
		return;
	cn[i][j][f] = sum[i][j][f] = 0;

	for (int k = 0; k <= (f ? 9 : s[i] - '0'); k++) {
		int a = j + (k >= d);
		int b = f || (k < s[i] - '0');

		dp(i + 1, a, b);
		
		(cn[i][j][f] += cn[i + 1][a][b]) %= mod;
		(sum[i][j][f] += sum[i + 1][a][b] + (k >= d) * p[j] * cn[i + 1][a][b]) %= mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	p[0] = 1;
	for (int i = 1; i < MX; i++)
		p[i] = 10 * p[i - 1] % mod;

	cin >> s;

	ll res = 0;
	for (int i = 1; i < 10; i++) {
		d = i;
		memset(cn, -1, sizeof(cn));
		dp(0, 0, 0);
		(res += sum[0][0][0]) %= mod;
	}

	cout << res << endl;

	return 0;
}