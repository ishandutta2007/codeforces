#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, a[150005], b[150005];
vi con;
map<ll, set<int>> pos;
map<int, ll> res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		pos[a[i]].insert(i);

	for (auto j = pos.begin(); j != pos.end(); j++) {
		ll i = j->fi;
		set<int> &st = pos[i];

		while (st.size() > 1) {
			auto it = st.begin();
			it++;

			pos[i * 2].insert(*it);
			st.erase(st.begin());
			st.erase(it);
		}

		if (st.size() == 1)
			res[*st.begin()] = i;
	}

	cout << res.size() << endl;
	for (auto x : res)
		cout << x.se << " ";
	cout << endl;

	return 0;
}