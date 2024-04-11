#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a[1000000] = {1};
	ll res = 0, M = 1e9+7, acu;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res += a[i]-1;
		res %= M;
	}

	for (int i = 2; i <= n; i++) {
		acu = acu * min(a[i]-1, min(a[i-1]-1, a[i-2]-1)) + min(a[i-1]-1, a[i]-1);
		acu %= M;

		res += acu * min(a[i]-1, a[i-1]-1);
		res %= M;
	}

	cout << res << endl;

	return 0;
}