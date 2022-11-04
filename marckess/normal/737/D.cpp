#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 4005, SQ = 90, inf = 1e9;
int n, a[MX], dp[MX][2*SQ][2*SQ], mx = 1e9;

int cost (int i, int j) {
	return a[j] - a[i-1];
}

int obtRes (int i, int j, int k, int f) {
	if (j - i + 1 < k) return 0;

	//mx = min(mx, k*f);
	int &res = dp[i][(n-j)-i-1+SQ][k*f+SQ];
	if (res != -2*inf) return res;
	
	if (f == 1) {
		if (j - i + 1 >= k + 1)
			res = max(
					cost(i, i+k-1) - obtRes(i+k, j, k, -1),
					cost(i, i+k) - obtRes(i+k+1, j, k+1, -1)
				);
		else
			res = cost(i, i+k-1) - obtRes(i+k, j, k, -1);
	} else {
		if (j - i + 1 >= k + 1)
			res = max(
					cost(j-k+1, j) - obtRes(i, j-k, k, 1),
					cost(j-k, j) - obtRes(i, j-k-1, k+1, 1)
				);
		else
			res = cost(j-k+1, j) - obtRes(i, j-k, k, 1);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < 2*SQ; j++)
			for (int k = 0; k < 2*SQ; k++)
				dp[i][j][k] = -2*inf;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	cout << obtRes(1, n, 1, 1) << endl;
	//cout << mx << endl;

	return 0;
}