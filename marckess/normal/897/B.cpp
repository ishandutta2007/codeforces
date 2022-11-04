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
typedef vector<vvi> vvvi;

ll obt (ll n) {
	ll res = n, x = n;
	
	while (x) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}

	return res;
} 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k, p;
	ll res = 0;
	ll acu = 1;

	cin >> k >> p;
	for (int i = 0; i < k; i++) {
		res += obt(acu++);
		res %= p;
	}

	cout << res << endl;

	return 0;
}