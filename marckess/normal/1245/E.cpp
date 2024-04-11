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

const int MX = 12;
int a[MX][MX], mul[] = {-1, 1};
ld mem[MX][MX][2];

ld dp (int i, int j, int f) {
	if (j < 0) {
		i--;
		j = abs(j) - 1;
	}
	if (j >= 10) {
		i--;
		j = 9 - (j - 9) + 1;
	}

	if (!i && !j) return 0;
	ld &res = mem[i][j][f];
	if (res >= 0) return res;
	res = 0;

	if (!i && j < 6) {
		for (int k = 1; k <= j; k++)
			res += dp(i, j - k, 1);
		res /= 6;
		res += 1;
		res *= 6.0l / j;
		return res;
	}

	for (int k = 1; k <= 6; k++)
		res += dp(i, j + k * mul[i % 2], 1) + 1;
	res /= 6;

	if (f && a[i][j]) {
		res = min(res, dp(i - a[i][j], j, 0));
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
			mem[i][j][0] = mem[i][j][1] = -1;
		}


	cout << fixed << setprecision(10) << dp(9, 0, 1) << endl;

	return 0;
}