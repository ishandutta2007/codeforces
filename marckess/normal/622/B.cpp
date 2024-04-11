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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll h, m, a;
	char c;

	cin >> h >> c >> m >> a;
	
	while (a--) {
		m++;
		if (m == 60) {
			m = 0;
			h++;
			h %= 24;
		}
	}

	if (h < 10) cout << 0;
	cout << h << ":";
	if (m < 10) cout << 0;
	cout << m << endl;

	return 0;
}