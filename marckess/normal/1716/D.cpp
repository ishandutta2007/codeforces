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
int n, k, dp[MX], res[MX];

void add (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

void main_() {
	cin >> n >> k;
	
	dp[0] = 1;
	for (int i = k, ini = k; ini <= n; i++, ini += i) {
		forn (j, n - i + 1)
			add(dp[j + i], dp[j]);
		
		for (int j = ini, l = 0; j <= n; j++, l++)
			add(res[j], dp[l]);
	}
	
	forr (i, 1, n)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}