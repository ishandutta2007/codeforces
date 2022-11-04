#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, x[11], y[11];

bool valid () {
	forn (i, m)
	forn (j, i)
		if (x[i] == x[j] || y[i] == y[j]) {
			return 0;
		}
	return 1;
}

void main_() {
	cin >> n >> m;
	forn (i, m)
		cin >> x[i] >> y[i];
	
	forn (i, m) {
		int ax = x[i];
		forr (j, 1, n) {
			x[i] = j;
			if (j != ax && valid()) {
				cout << "YES" << endl;
				return;
			}
		}
		x[i] = ax;
		
		int ay = y[i];
		forr (j, 1, n) {
			y[i] = j;
			if (j != ay && valid()) {
				cout << "YES" << endl;
				return;
			}
		}
		y[i] = ay;
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}