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

const int MX = 100005;
int n, mem[MX][3][2];
string s;

int dp (int i, int j, int f) {
	if (i == n || j > 2) return 0;
	
	int &res = mem[i][j][f];
	if (res != -1)
		return res;
	res = dp(i, j + 1, f);
	
	if ((s[i] - '0' == f) ^ (j == 1))
		res = max(res, dp(i + 1, j, 1 - f) + 1);
	else
		res = max(res, dp(i + 1, j, f));
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	memset(mem, -1, sizeof(mem));
	cout << max(dp(0, 0, 0), dp(0, 0, 1)) << endl;

	return 0;
}