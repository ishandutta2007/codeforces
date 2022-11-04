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

const int MX = 105;
int n, a[MX], mem[MX][3];

int dp (int i, int f) {
	if (i == n) return 0;
	int &res = mem[i][f];
	if (res != -1) return res;
	res = dp(i+1, 0) + 1;

	if ((a[i] & 1) && !(f & 1))
		res = min(res, dp(i+1, 1));

	if ((a[i] & 2) && !(f & 2))
		res = min(res, dp(i+1, 2));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;

	return 0;
}