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
typedef vector<ii> vii;

const int MX = 200005;
string s;
int q;
vi pos[256];

int count (char c, int l, int r) {
	return upper_bound(all(pos[c]), r) - lower_bound(all(pos[c]), l);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> q;
	for (int i = 0; i < s.size(); i++)
		pos[s[i]].pb(i + 1);

	while (q--) {
		int l, r;
		cin >> l >> r;

		string res = "Yes";
		if (l < r)
			if (s[l - 1] == s[r - 1]) {
				int cn = 0;

				for (char c = 'a'; c <= 'z'; c++)
					if (c != s[l - 1])
						cn += bool(count(c, l, r));      

				if (cn <= 1)
					res = "No";
			}

		cout << res << endl;
	}

	return 0;
}