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
string s;

bool go (char a, char b, char c) {
	string t;
	for (char h : s) {
		if (h == 'A') t.pb(a);
		if (h == 'B') t.pb(b);
		if (h == 'C') t.pb(c);
	}
	int x = 0;
	for (char h : t) {
		if (h == '(') x++;
		else x--;
		if (x < 0) return 0;
	}
	return !x;
}

void solve () {
	cin >> s;
	n = s.size();
	
	forn (i, 2) forn (j, 2) forn (k, 2)
		if (go("()"[i], "()"[j], "()"[k])) {
			cout << "YES" << endl;
			return;
		}
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}