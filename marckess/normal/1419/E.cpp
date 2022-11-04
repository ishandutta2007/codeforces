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

int n;
set<int> st;
vi p;

void solve () {
	cin >> n;

	st.clear();
	p.clear();

	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) {
			st.insert(i);
			st.insert(n / i);
		}
	st.erase(1);

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			p.pb(i);
			while (n % i == 0)
				n /= i;
		}

	if (n > 1) p.pb(n);

	if (p.size() == 1) {
		for (int r : st)
			cout << r << " ";
		cout << endl << 0 << endl;
		return;
	}

	if (st.size() == 3 && p.size() == 2) {
		for (int r : st)
			cout << r << " ";
		cout << endl << 1 << endl;
		return;
	}

	vi res;

	for (int x : st)
		if (x % (p[0] * p.back()) == 0) {
			res.pb(x);
			break;
		}
	st.erase(res[0]);

	forn (i, p.size()) {
		int f = p[i] * p[(i + 1) % (int)p.size()];
		int ult = -1;

		for (int x : st)
			if (x % f == 0) {
				ult = x;
				break;
			}
		st.erase(ult);

		vi act;
		for (int x : st)
			if (x % p[i] == 0) {
				res.pb(x);
				act.pb(x);
			}

		for (int x : act)
			st.erase(x);

		if (ult != -1) res.pb(ult);
	}

	for (int x : res)
		cout << x << " ";
	cout << endl << 0 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}