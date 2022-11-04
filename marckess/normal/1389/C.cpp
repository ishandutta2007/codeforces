#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int res;
string s;

void solve () {
	cin >> s;
	res = 0;

	for (int x = '0'; x <= '9'; x++) {
		for (int y = '0'; y <= '9'; y++) {
			int p = 0, f = 0;

			forn (i, s.size()) {
				if (f == 0 && s[i] == x) {
					f = 1;
					if (x == y) p++;
				} else if (f == 1 && s[i] == y) {
					f = 0;
					p++;
					if (x != y) p++;
				}
			}

			res = max(res, p);
		}
	}

	cout << int(s.size()) - res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) 
		solve();	

	return 0;
}