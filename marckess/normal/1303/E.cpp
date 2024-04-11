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

const int MX = 401;
int mem[MX][MX][MX];
string s, t;

int dp (int i, int j, int k) {
	if (i == s.size()) {
		if (k == t.size())
			return j;
		return -1e9;
	}

	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = dp(i + 1, j, k);

	if (j < t.size() && s[i] == t[j])
		res = max(res, dp(i + 1, j + 1, k));

	if (k < t.size() && s[i] == t[k])
		res = max(res, dp(i + 1, j, k + 1));

	return res;
}

void solve () {
	cin >> s >> t;

	for (int i = 0; i <= s.size(); i++)
		for (int j = 0; j <= t.size(); j++)
			for (int k = 0; k <= t.size(); k++)
				mem[i][j][k] = -1;

	for (int i = 0; i <= t.size(); i++)
		if (dp(0, 0, i) >= i) {
			cout << "YES" << endl;
			return;
		}

	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}