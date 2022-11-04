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

const int MX = 2000005, mod = 1000000007;
int n, mem[MX][2];

ll dp (int n, int f) {
	if (n <= 2) return 0;

	int &res = mem[n][f];
	if (res != -1) return res;

	if (f) {
		res = max(
			dp(n - 1, 0) + 2 * dp(n - 2, 0) + 4,
			dp(n - 1, 1) + 2 * dp(n - 2, 1)
		) % mod;
	} else {
		res = (dp(n - 1, 1) + 2 * dp(n - 2, 1)) % mod;
	}

	return res;
} 

void solve () {
	cin >> n;
	cout << dp(n, 1) << endl;	
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}