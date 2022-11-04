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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a;
set<int> st;
vi v, res;

void no () {
	cout << -1 << endl;
	exit(0);
}

void check () {
	set<int> st;
	res.pb(v.size());

	for (int x : v) {
		if (a > 0) {
			if (st.count(x))
				no();
			st.insert(x);
		}
	}

	v.clear();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> a;
		v.pb(a);

		if (a < 0) {
			a *= -1;
			if (!st.count(a))
				no();
			st.erase(a);
		} else {
			if (st.count(a))
				no();
			st.insert(a);
		}

		if (st.empty())
			check();
	}

	if (st.size())
		no();

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}