
// Problem : D. Make Them Equal
// Contest : Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1633/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int MX = 1005;
int n, k, b[MX], c[MX], to[MX], mem[MX][12 * MX];
ii a[MX];

int dp (int i, int k) {
	if (k < 0) return -2e9;
	if (i == n) return 0;
	
	int &res = mem[i][k];
	if (res != -1) return res;
	
	return res = max(
		dp(i + 1, k),
		dp(i + 1, k - a[i].fi) + a[i].se
	);
}

void main_() {
	cin >> n >> k;
	
	int ned = 0, tot = 0;
	forn (i, n) {
		cin >> b[i];
		ned += to[b[i]];
	}
	
	forn (i, n) {
		cin >> c[i];
		a[i] = {to[b[i]], c[i]};
		tot += c[i];
	}
	
	if (ned <= k) {
		cout << tot << endl;
		return;
	}
	
	forn (i, n)
		memset(mem[i], -1, sizeof(mem[i]));
	cout << dp(0, k) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	iota(to, to + MX, -1);
	forr (i, 1, MX - 1)
		forr (x, 1, i)
			to[i + i / x] = min(to[i + i / x], to[i] + 1);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}