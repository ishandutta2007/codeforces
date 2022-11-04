#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

string s;

void solve () {
	ll res = 0, c = 0;
	cin >> s;
	forn (i, s.size()) {
		if (s[i] == '0') c++;
		else {
			for (int j = i; j < s.size() && j - i + 1 < 20; j++) {
				int x = stoi(s.substr(i, j - i + 1), nullptr, 2);
				res += j - i + 1 <= x && x <= j - i + 1 + c;
			}
			c = 0;
		}
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}