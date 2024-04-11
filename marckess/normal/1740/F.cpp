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

typedef vector<vvi> vvvi;

const int MX = 2005, mod = 998244353;
int n, a[MX], cn[MX], gre[MX], acu[MX];
vvvi mem;

int techo (int a, int b) {
	return (a + b - 1) / b;
}

int dp (int i, int j, int k) {
	if (k > n) return 0;
	if (k == n) return 1;
	if (j == 0) return 0;
	
	auto &res = mem[i][j][k];
	if (res != -1)
		return res;
	
	res = dp(i, j - 1, k);
	
	if (k + j <= acu[i]) {
		res += dp(i + 1, j, k + j);
		
		if (res >= mod)
			res -= mod;
	}
	
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	
	forr (i, 1, n) {
		forr (j, 1, n)
			gre[i] += cn[j] >= i;
		acu[i] = gre[i] + acu[i - 1];
	}
	
	mem = vvvi(n + 1);
	forr (i, 1, n) {
		if (i == 1) {
			mem[i] = vvi(n + 1, vi(n + 1, -1));
		} else {
			mem[i] = vvi(techo(n, i - 1) + 1, vi(n + 1, -1));
		}
	}
	cout << dp(1, n, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}