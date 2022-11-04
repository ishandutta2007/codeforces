#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int k, n, m, c[105], p[105][105];
ll dp[105][105][105];

ll obtRes (int i, int j, int l) {
	if (i == n && j == k)
		return 0;

	if (i >= n || j > k)
		return 1e18;

	ll &res = dp[i][j][l];

	if (res != -1)
		return res;
	res = 1e18;

	if (c[i]) {

		if (l == c[i])
			res = obtRes(i+1, j, c[i]);
		else
			res = obtRes(i+1, j+1, c[i]);

	} else {

		for (int h = 1; h <= m; h++)
			if (h == l)
				res = min(res, obtRes(i+1, j, h) + p[i][h]);
			else
				res = min(res, obtRes(i+1, j+1, h) + p[i][h]);

	}

	return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    	cin >> c[i];

    for (int i = 0; i < n; i++)
    	for (int j = 1; j <= m; j++)
    		cin >> p[i][j];

    for (int i = 0; i < 105; i++)
    	for (int j = 0; j < 105; j++)
    		for (int l = 0; l < 105; l++)
    			dp[i][j][l] = -1;

    ll res = obtRes (0, 0, 0);

    if (res == 1e18)
    	cout << -1 << endl;
    else
    	cout << res << endl;

    return 0;
}