#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n, m, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	if (n > m) swap(n, m);

	if (n == 1) {
		res = 6 * (m / 6);
		res += 2 * max(0ll, m % 6 - 3);
	} else if (n == 2) {
		if (m == 2) res = 0;
		else if (m == 3) res = 4;
		else if (m == 7) res = 12;
		else res = n * m;
	} else {
		res = n * m - (n * m % 2);
	}

	cout << res << endl;

	return 0;
}