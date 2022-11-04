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

ll x;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x;
	
	int mn = 360, res = 0;

	for (int i = 0; i < 4; i++) {
		int d = min(MOD(-x+90*i, 360), 360 - MOD(-x+90*i, 360));
		if (d < mn) {
			mn = d;
			res = i;
		}
	}

	cout << res << endl;

	return 0;
}