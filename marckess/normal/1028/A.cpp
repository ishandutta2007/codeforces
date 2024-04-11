#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 120;
int n, m, bx = 0, ax = 1e9, by = 0, ay = 1e9;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == 'B') {
				ax = min(ax, i);
				ay = min(ay, j);
				bx = max(bx, i);
				by = max(by, j);
			}
		}

	cout << (ax + bx) / 2 << " " << (ay + by) / 2 << endl;

	return 0;
}