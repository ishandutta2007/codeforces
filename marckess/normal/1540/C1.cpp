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

const int MX = 105, mod = 1000000007;
ll kk, mem[MX * MX][MX], ned[MX], n, c[MX], b[MX], x, suf[MX];

ll dp (int s, int i) {
	if (i && s < ned[i - 1]) return 0;
	if (i == n) return 1;
	
	ll &res = mem[s][i];
	if (res != -1) return res;
	res = 0;
	
	for (int j = 0; j <= c[i]; j++) {
		res += dp(s + j, i + 1);
		if (res >= mod)
			res -= mod;
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	forn (i, n) cin >> c[i];
	forn (i, n - 1) cin >> b[i];
	cin >> kk >> x;
	
	forn (i, n) {
		ned[i] = (i + 1) * x;
		for (int j = i - 1, k = 1; j >= 0; j--, k++)
			ned[i] += k * b[j];
	}
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;
		
	return 0;
}