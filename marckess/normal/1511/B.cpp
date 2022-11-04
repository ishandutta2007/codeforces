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

int a, b, c;

void solve () {
	cin >> a >> b >> c;
	
	int g = 0;
	forn (kk, c)
		g = 10 * g + 1;
	
	int x = g, y = g;
	
	while (1) {
		string s = to_string(x);
		if (s.size() == a)
			break;
		x *= 2;
	}
	
	while (1) {
		string s = to_string(y);
		if (s.size() == b)
			break;
		y *= 3;
	}
	
	cout << x << " " << y << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
    
	return 0;
}