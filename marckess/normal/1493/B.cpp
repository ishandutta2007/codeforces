#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int h, m;
void solve () {
	char a, b, kk, c, d;
	cin >> h >> m;
	cin >> a >> b >> kk >> c >> d;
	
	a -= '0';
	b -= '0';
	c -= '0';
	d -= '0';
	
	int x = a * 10 + b;
	int y = c * 10 + d;
	
	map<int, int> st = {
    	{0, 0},
    	{1, 1},
    	{2, 5},
    	{5, 2},
    	{8, 8}
    };
	 
	while (x < h) {
		if (st.count(x / 10) && st.count(x % 10) && st.count(y / 10) && st.count(y % 10)) {
			int f = 10 * st[x % 10] + st[x / 10];
			int g = 10 * st[y % 10] + st[y / 10];
			
			if (g < h && f < m) {
				cout << x / 10 << x % 10 << ":" << y / 10 << y % 10 << endl;
				return;
			}
		}
		
		y++;
		if (y == m) {
			x++;
			y = 0;
		}
	}
	
	cout << "00:00" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}