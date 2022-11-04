#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
string s;
vector<vi> res;
set<int> c, u;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++)
		if (s[i] == '0') c.insert(i);
		else u.insert(i);

	while (c.size()) {
		int act = *c.begin(), f = 1;
		c.erase(c.begin());
		res.emplace_back(1, act);

		while (1) {
			set<int>::iterator it;
			if (f) {
				it = u.lower_bound(act);
				if (it == u.end()) break;
				act = *it;
				u.erase(it);
			} else {
				it = c.lower_bound(act);
				if (it == c.end()) break;
				act = *it;
				c.erase(it);
			}
			f = 1 - f;
			res.back().pb(act);
		}

		if (!f) {
			cout << -1 << endl;
			return 0;
		}
	}

	if (u.size()) {
		cout << -1 << endl;
		return 0;
	}

	cout << res.size() << endl;

	for (auto &v : res) {
		cout << v.size();
		for (int x : v) cout << " " << x+1;
		cout << endl;
	}

	return 0;
}