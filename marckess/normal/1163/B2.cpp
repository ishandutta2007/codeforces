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

const int MX = 100005;
int n, u, cn[MX], f[MX], d = 0, res = 0;
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> u;

		f[cn[u]]--;
		if (cn[u] && !f[cn[u]]) st.erase(cn[u]);
		cn[u]++;
		f[cn[u]]++;
		if (!st.count(cn[u])) st.insert(cn[u]);

		if (st.size() == 1) {
			if (*st.begin() == 1 || f[*st.begin()] == 1)
				res = i;
		} else if (st.size() == 2) {
			auto it = st.begin();
			int x = *it;
			it++;
			int y = *it;

			if (x == 1 && f[x] == 1) res = i;
			if (y - x == 1 && f[y] == 1) res = i;
		}
	}

	cout << res << endl;

	return 0;
}