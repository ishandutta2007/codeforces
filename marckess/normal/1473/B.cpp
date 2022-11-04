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

string a, b;

void solve () {
	cin >> a >> b;
	string s;
	
	forn (kk, b.size()) {
		s += a;
		if (s.size() % b.size() == 0) {
			int f = 1;
			forn (i, s.size())
				f &= s[i] == b[i % b.size()];
			if (f) {
				cout << s << endl;
				return;
			}
		}
	}
	
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}