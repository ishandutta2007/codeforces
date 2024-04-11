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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, res;
set<ii> st[MX];

void insert (set<ii> &st, ii p) {
	res++;
	st.insert(p);

	auto it = st.lower_bound(p);
	auto jt = it;
	jt++;

	if (jt != st.end() && it->se + 1 == jt->fi) {
		ii aux(it->fi, jt->se);

		res--;
		st.erase(it);
		st.erase(jt);

		st.insert(aux);
	}

	it = st.lower_bound(p);
	if (it != st.begin()) {
		jt = it;
		jt--;

		if (jt->se + 1 == it->fi) {
			ii aux(jt->fi, it->se);

			res--;
			st.erase(it);
			st.erase(jt);

			st.insert(aux);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	forn (i, n) {
		int t;
		cin >> t;
		insert(st[t], {i, i});
	}

	cout << res - 1 << endl;

	while (--m) {
		int a, b;
		cin >> a >> b;

		if (st[a].size() < st[b].size())
			swap(st[a], st[b]);

		for (const ii &k : st[b]) {
			res--;
			insert(st[a], k);
		}

		cout << res - 1 << endl;
	}

	return 0;
}