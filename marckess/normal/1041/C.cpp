#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, d, res[MX], a;
set<ii> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> d;
	d++;

	for (int i = 0; i < n; i++) {
		cin >> a;
		st.emplace(a, i);
	}

	int i = 1;
	while (st.size()) {
		auto act = st.begin();

		while (st.size()) {
			res[act->se] = i;
			
			int x = act->fi+d;
			st.erase(act);

			if (st.empty()) break;

			act = st.lower_bound({x, -1});
			if (act == st.end()) break;
		}

		i++;
	}

	cout << i-1 << endl;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}