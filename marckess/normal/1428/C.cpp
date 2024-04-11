#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s, res;

void solve () {
	cin >> s;
	
	res.clear();
	
	for (char c : s) {
		if (c == 'A') res.pb('A');
		if (c == 'B') {
			if (res.size() && res.back() == 'A') res.pop_back();
			else res.pb('B');
		}
	}
	
	s.clear();
	
	for (char c : res) {
		if (c == 'A') s.pb('A');
		if (c == 'B') {
			if (s.size() && s.back() == 'B') s.pop_back();
			else s.pb('B');
		}
	}
	
	cout << s.size() << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}