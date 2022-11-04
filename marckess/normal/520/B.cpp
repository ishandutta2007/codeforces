#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, c = 1, res = 0;

	cin >> n >> m;
	while (n < m) {
		n *= 2;
		c *= 2;
		res++;
	}

	n -= m;
	while (n > 0) {
		res += n / c;
		n %= c;
		c /= 2;
	}

	cout << res << endl;

	return 0;
}