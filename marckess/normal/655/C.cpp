#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

int n, k, res;
string s;

set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;
	res = n;

	for (int i = 0, j = -1, cn = 0; i < n;) {
		while (j + 1 < n && cn <= k) {
			j++;
			if (s[j] == '0') {
				st.insert(j);
				cn++;
			}
		}

		if (cn <= k) break;
		if (s[i] == '1') {
			i++;
			continue;
		}

		auto it = st.lower_bound((i + j) / 2);

		forn (kk, 4) if (it != st.begin()) it--;

		forn (kk, 8) if (it != st.end()) {
			int x = abs(*it - i);
			int y = abs(*it - j);
			res = min(res, max(x, y));
			it++;
		}

		if (s[i] == '0') cn--;
		i++;
	}

	cout << res << endl;
	
	return 0;
}