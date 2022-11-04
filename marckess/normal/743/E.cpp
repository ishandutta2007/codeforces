#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

typedef vector<vi> vvi;
vvi psi(10), dp;
vi a;
int n;

int valMx (int i, int eleg, int m) {
	if ( eleg == (1 << 8) - 1 || ( i == n && m == 0 ))
		return 0;
	
	if ( i >= n )
		return -1e9;

	if ( dp[i][eleg] > -2e9 )
		return dp[i][eleg];

	int mx = valMx(i+1, eleg, m), k = a[i];
	
	if ( !isOn(eleg, k-1) ) {
		int l = lower_bound(psi[k].begin(), psi[k].end(), i) - psi[k].begin();
		
		if ( l + m - 1 < psi[k].size() )
			mx = max(mx, valMx(psi[k][l+m-1] + 1, setBit(eleg, k-1), m) + m);
		
		if ( l + m < psi[k].size() )
			mx = max(mx, valMx(psi[k][l+m] + 1, setBit(eleg, k-1), m) + m + 1);
	}

	return dp[i][eleg] = mx;
}

int obtRes () {
	int i = 0, j = 1000, m = (i + j) / 2;
	for (int l = 0; l < 12; l++) {
		dp = vvi(n + 2, vi(1 << 8, -2e9));
		if ( valMx(0, 0, m) >= 0 )
			i = m;
		else
			j = m;
		m = (i + j) / 2;
		dp = vvi(n + 2, vi(1 << 8, -2e9));
	}
	return valMx(0, 0, m);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	a = vi(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		psi[a[i]].push_back(i);
	}

	cout << obtRes() << endl;

	return 0;
}