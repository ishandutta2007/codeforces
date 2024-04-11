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

const int MX = 100005;
int n, m, s, r, res = 0, cn[MX];
vi a[MX];
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (n--) {
		cin >> s >> r;
		a[s].pb(r);
		st.insert(s);
	}

	for (int i = 1; i <= m; i++) 
		sort(all(a[i]), greater<int>());

	for (int i = 0; i < MX; i++) {
		auto it = st.begin();
		int acu = 0;

		while (it != st.end()) {
			if (a[*it].size() <= i) {
				auto aux = it;
				it++;
				st.erase(aux);
				continue;
			}

			cn[*it] += a[*it][i];

			if (cn[*it] < 0) {
				auto aux = it;
				it++;
				st.erase(aux);
				continue;
			}

			acu += cn[*it];
			it++;
		}

		res = max(res, acu);
	}

	cout << res << endl;

	return 0;
}