#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000;
int n, c[MX], a[MX], dp[MX][10];
string s;

int obtRes (int i, int j) {
	if (i == n) return j == 7 ? 0 : 1e9;

	int &res = dp[i][j];
	if (res != -1) return res;

	return res = min(obtRes(i+1, j), obtRes(i+1, j | a[i]) + c[i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = -1;	

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> s;
		for (char c : s) a[i] |= (1 << (c-'A'));
	}

	int res = obtRes(0, 0);
	if (res >= 1e9) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}