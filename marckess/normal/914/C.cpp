#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int M = 1e9+7;
ll dp[1005], C[1005][1005];

void precal (int x) {
	int c = 0;
	for (int i = 0, j = 1; i < 12; i++, j *= 2)
		if (x & j)
			c++;

	dp[x] = dp[c] + 1;
}

ll comb (int n, int k) {
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
	if (C[n][k] != -1)
		return C[n][k];
	return C[n][k] = (comb(n-1, k-1) + comb(n-1,k)) % M;
}

string n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	//------------
	fill(dp, dp+1005, -1);
	dp[1] = 0;
	for (int i = 2; i <= 1e3; i++) {
		precal(i);
	}

	for (int i = 0; i < 1005; i++)
		fill(C[i], C[i]+1005, -1);
	//------------------
	
	ll res = 0;
	int k, u = 0;
	cin >> n >> k;
	
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i <= n.size(); i++) {
		if (dp[i] == k-1) {
			res += comb(n.size(), i);
			res %= M;
		}

		if (n[i-1] == '1')
			u++;
	}

	for (int i = n.size()-1; i >= 0; i--) {
		if (n[i] == '1') {
			u--;
		} else {
			for (int j = u+1; j <= n.size(); j++) {
				if (dp[j] == k-1) {
					res -= comb(n.size()-i-1, j-u-1);
					res = MOD(res, M);
				}
			}
		}
	}

	if (k == 1)
		cout << MOD(res-1, M) << endl;
	else
		cout << res << endl;

	return 0;
}