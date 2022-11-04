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

const int mod = 1000000007;
int n, m, mem[10][1001][1001][2], res;

int dp (int i, int a, int b, int f) {
	if (a > b) return 0;
	if (!b) return 0;
	if (i == m) return 1;

	int &res = mem[i][a][b][f];
	if (res != -1) return res;
	res = dp(i+1, a, b, 0);

	if (!f) res += dp(i, a+1, b, f);
	else res += dp(i, a, b-1, f);
	if (res >= mod) res -= mod;

	if (!f) res += dp(i, a, b-1, 1);
	if (res >= mod) res -= mod;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	memset(mem, -1, sizeof(mem));
	cin >> n >> m;
	cout << dp(0, 1, n, 0) << endl;

	return 0;
}