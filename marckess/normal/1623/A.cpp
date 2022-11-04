// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

int n, m;

void main_() {
	int x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	
	int dx = 1, dy = 1;
	forn (i, 1e9) {
		if (x1 == x2 || y1 == y2) {
			cout << i << endl;
			return;
		}
		
		if (x1 + dx < 1 || n < x1 + dx) dx = -dx;
		if (y1 + dy < 1 || m < y1 + dy) dy = -dy;
		
		x1 += dx;
		y1 += dy;
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