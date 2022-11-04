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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
string s, t, res = "abc";

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s >> t;
	if (s[0] == s[1] || t[0] == t[1]) {
		do {
			bool f = 1;
			for (int i = 0; i < 3; i++) {
				f &= res[i] != s[0] || res[(i+1)%3] != s[1];
				f &= res[i] != t[0] || res[(i+1)%3] != t[1];
			}
			if (f) {
				cout << "YES" << endl;
				forn(i, 3 * n) cout << res[i % 3];
				cout << endl;
				return 0;
			}
		} while (next_permutation(all(res)));
	} else {
		do {
			bool f = 1;
			for (int i = 0; i < 2; i++) {
				f &= res[i] != s[0] || res[(i+1)%3] != s[1];
				f &= res[i] != t[0] || res[(i+1)%3] != t[1];
			}
			if (f) {
				cout << "YES" << endl;
				forn(i, 3 * n) cout << res[i / n];
				cout << endl;
				return 0;
			}
		} while (next_permutation(all(res)));
	}

	cout << "NO" << endl;

	return 0;
}