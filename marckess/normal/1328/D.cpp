#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, t[MX], mem[MX][10];

int dp (int i, int f) {
	if (i == n) return f == 1 && t[n - 1] != t[0] ? 1e9 : f;
	int &res = mem[i][f];
	if (res != -1) return res;
	res = 1e9;

	for (int j = 1; j < 10; j++)
		if (t[i] == t[i - 1] || j != f)
			res = min(res, max(j, dp(i + 1, j)));

	return res;
}

void rec (int i, int f) {
	cout << f << " ";
	if (i == n) return;
	int res = mem[i][f];

	for (int j = 1; j < 10; j++)
		if (t[i] == t[i - 1] || j != f)
			if (res == max(j, dp(i + 1, j)))
				return rec(i + 1, j);
}

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		memset(mem[i], -1, sizeof(mem[i]));
	}

	cout << dp(1, 1) << endl;
	rec(1, 1);
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}