#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, t, d, a = 0, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a += t;
		if (i) {
			res += 2;
			a += 10;
		}
	}

	if (a > d) {
		cout << - 1 << endl;
		return 0;
	}

	while (a + 5 <= d) {
		a += 5;
		res++;
	}

	cout << res << endl;

	return 0;
}