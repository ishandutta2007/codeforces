#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

string s, t;
vi pos[256];

void solve () {
	cin >> s >> t;

	for (int i = 'a'; i <= 'z'; i++)
		pos[i].clear();
	
	for (int i = 0; i < s.size(); i++)
		pos[s[i]].pb(i);

	int p = 0, res = 1;
	for (int i = 0; i < t.size(); ) {
		char c = t[i];
		int j = lower_bound(all(pos[c]), p) - pos[c].begin();

		if (j == pos[c].size()) {
			if (p == 0) {
				cout << -1 << endl;
				return;
			}

			res++;
			p = 0;
			continue;
		}

		p = pos[c][j] + 1;
		i++;
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