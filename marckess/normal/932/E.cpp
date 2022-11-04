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

const int MX = 5005, mod = 1e9+7;
int dp[MX][MX];
int n, k;

int pot (ll b, int p) {
	ll res = 1;

	while (p) {
		if (p & 1)
			res = (res * b) % mod;
		b = (b * b) % mod;
		p /= 2;
	}

	return res;
}

int obtRes (ll k, ll b) {
	int &res = dp[k][b];
	if (res != -1)
		return res;

	if (k == 0)
		return res = pot(2, n - b);
	return res = (b * obtRes(k - 1, b) + (n - b) * obtRes(k - 1, b + 1)) % mod;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < MX; i++)
    	for (int j = 0; j < MX; j++)
    		dp[i][j] = -1;

    cin >> n >> k;
    cout << obtRes(k, 0) << endl;

    return 0;
}