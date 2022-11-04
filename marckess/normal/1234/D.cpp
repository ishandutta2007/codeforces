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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, c[MX];
set<int> st[26];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++) {
		c[i] = s[i-1] - 'a';
		st[c[i]].insert(i);
	}

	cin >> q;
	while (q--) {
		int op, l, r;
		char in;
		cin >> op >> l;

		if (op == 1) {
			cin >> in;
			st[c[l]].erase(l);

			c[l] = in - 'a';
			st[c[l]].insert(l);
		} else {
			cin >> r;
			int res = 0;

			for (int i = 0; i < 26; i++) {
				auto it = st[i].lower_bound(l);
				if (it != st[i].end() && *it <= r)
					res++;
			}

			cout << res << endl;
		}
	}

	return 0;
}