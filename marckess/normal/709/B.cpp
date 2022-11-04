#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a, x[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x+n);

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (a <= x[0]) {
		cout << x[n-2] - a << endl;
		return 0;
	}

	if (a >= x[n-1]) {
		cout << a - x[1] << endl;
		return 0;
	}

	cout << min(
			(x[n-2] - x[0]) + min(abs(a - x[0]), abs(x[n-2] - a)),
			(x[n-1] - x[1]) + min(abs(a - x[1]), abs(x[n-1] - a)) 
		) << endl;

	return 0;
}