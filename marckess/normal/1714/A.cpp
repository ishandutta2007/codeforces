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

int n, x, y, h[11], m[11];

void main_() {
	cin >> n >> x >> y;
	forn (i, n)
		cin >> h[i] >> m[i];
	
	forn (res, 1e9) {
		forn (i, n)
			if (x == h[i] && y == m[i]) {
				cout << res / 60 << " " << res % 60 << endl;
				return;
			}
		
		y++;
		if (y == 60) {
			y = 0;
			x++;
		}
		x %= 24;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}