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
typedef vector<ii> vii;

int mem[105][205][305];
int n, t, a[105], cn[305];

int dp (int i, int j, int k) {
	if (j == t) return 0;
	if (i == n) {
		if (j + 1 == n) return max(0, t - 2 * n) * cn[k] + dp(0, j + 1, k);
		if (j + 1 == 2 * n) return 0;
		return dp(0, j + 1, k);
	}
	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = dp(i + 1, j, k);
	if (a[i] >= k) res = max(res, dp(i + 1, j, a[i]) + 1);
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> n >> t;
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	cout << dp(0, 0, 0) << endl;

	return 0;
}