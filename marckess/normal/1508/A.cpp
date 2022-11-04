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

int n;
string a, b, c;

bool go (string &a, string &b) {
	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	
	for (char c : a) {
		if (c == '0') x1++;
		else y1++;
	}
	for (char c : b) {
		if (c == '0') x2++;
		else y2++;
	}
	
	int g = 0;
	char t = 0;
	if (min(x1, x2) >= n) t = '0', g = min(x1, x2);
	if (min(y1, y2) >= n) t = '1', g = min(y1, y2);
	
	if (!t) return 0;
	
	vector<string> v1(g + 1);
	vector<string> v2(g + 1);
	
	for (char c : a) {
		if (c == t && g) g--;
		else v1[g].pb(c);
	}
	
	g = (int)v1.size() - 1;
	for (char c : b) {
		if (c == t && g) g--;
		else v2[g].pb(c);
	}
	
	reverse(all(v1));
	reverse(all(v2));
	
	forn (i, v1.size()) {
		if (i) cout << t;
		for (char c : v1[i]) cout << c;
		for (char c : v2[i]) cout << c;
	}
	cout << endl;
	
	return 1;
}

void solve () {
	cin >> n >> a >> b >> c;
	
	if (go(a, b)) return;
	if (go(a, c)) return;
	if (go(b, c)) return;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}