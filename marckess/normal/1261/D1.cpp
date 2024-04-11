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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2005, mod = 998244353;
int n, k, a[MX], mem[MX][2*MX];

int dp (int i, int j) {
	if (i == n) return j > MX;
	int &res = mem[i][j];
	if (res != -1)
		return res;
	
	if (a[i] == a[(i+1)%n])
		return res = 1ll * k * dp(i+1, j) % mod;
	return res = (dp(i+1, j-1) + dp(i+1, j+1) + 1ll * (k - 2) * dp(i+1, j)) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(mem, -1, sizeof(mem));
	cout << dp(0, MX) << endl;

	return 0;
}