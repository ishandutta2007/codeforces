#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 5002;
int n, a[MX], dp[MX][MX];

int obtRes (int i, int j) {
	if (i == n) return 0;

	int &res = dp[i][j];
	if (res != -1) return res;

	if (j >= a[i]) return res = obtRes(i+1, min(j, a[i]));

	res = obtRes(i+1, j) + 1;
	if (a[i] < MX) res =  min(res, obtRes(i+1, a[i]) + a[i] - j);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			dp[i][j] = -1;

	cin >> n;
	forn (i, n) cin >> a[i];

	cout << obtRes(0, 0) << endl;

	return 0;
}