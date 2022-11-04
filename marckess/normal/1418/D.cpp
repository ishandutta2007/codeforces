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
int n, q;
set<int> st;
multiset<int> dif;

int res () {
	if (st.size() < 3) return 0;
	return *st.rbegin() - *st.begin() - *dif.rbegin();
}

void insert (int x) {
	auto it = st.lower_bound(x);

	if (it != st.begin() && it != st.end()) {
		auto jt = it;
		jt--;
		dif.erase(dif.find(*it - *jt));
	}

	it = st.insert(x).fi;

	auto jt = it;
	jt++;
	if (jt != st.end()) {
		dif.insert(*jt - *it);
	}

	if (it != st.begin()) {
		jt = it;
		jt--;
		dif.insert(*it - *jt);
	}
}

void erase (int x) {
	auto it = st.lower_bound(x);

	auto jt = it;
	jt++;
	if (jt != st.end()) {
		dif.erase(dif.find(*jt - *it));
	}

	if (it != st.begin()) {
		jt = it;
		jt--;
		dif.erase(dif.find(*it - *jt));
	}

	st.erase(x);

	it = st.lower_bound(x);

	if (it != st.begin() && it != st.end()) {
		auto jt = it;
		jt--;
		dif.insert(*it - *jt);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	while (n--) {
		int p;
		cin >> p;
		insert(p);
	}

	cout << res() << endl;

	while (q--) {
		int t, x;
		cin >> t >> x;

		if (t) insert(x);
		else erase(x);

		cout << res() << endl;
	}

	return 0;
}