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

const int MX = 100005;
int n, k, z, a[MX], res, s, mem[MX][6][2];

int dp (int i, int z, int f, int k) {
	if (!k) return a[i];

	int &res = mem[i][z][f];
	if (res != -1) return res;
	res = a[i];

	return res += max(
		dp(i + 1, z, 1, k - 1),
		f && z && i ? dp(i - 1, z - 1, 0, k - 1) : 0
	);
}

void solve () {
	cin >> n >> k >> z;
	forn (i, n) cin >> a[i];

	forn (i, n + 1) memset(mem[i], -1, sizeof(mem[i]));
	cout << dp(0, z, 1, k) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) 
		solve();	

	return 0;
}