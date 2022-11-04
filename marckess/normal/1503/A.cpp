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

string s, a, b;
int n, x, y;

void solve () {
	cin >> n >> s;
	x = y = 0;
	a = b = "";
	
	for (char c : s) {
		x += c == '0';
		y += c == '1';
	}
	
	if (s[0] != s.back() || s[0] != '1' || x % 2 || y % 2) {
		cout << "NO" << endl;
		return;
	}
	
	for (char c : s) {
		if (c == '1') {
			if (y) {
				a.pb('(');
				b.pb('(');
				y -= 2;
			} else {
				a.pb(')');
				b.pb(')');
			}
		} else {
			if (x % 2) {
				a.pb('(');
				b.pb(')');
				x--;
			} else {
				a.pb(')');
				b.pb('(');
				x--;
			}
		}
	}
	
	cout << "YES" << endl << a << endl << b << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}