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

const int MX = 505;
int n;
vi a, b;

vi f (vi a) {
	int i = 0, j = n - 1;
	vi res;
	
	while (i < j) {
		res.pb(a[i++]);
		res.pb(a[j--]);
	}

	return res;
}

void solve () {
	cin >> n;
	a = b = vi(n);

	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;

	if (n & 1)
		if (a[n / 2] != b[n / 2]) {
			cout << "No" << endl;
			return;
		}

	a = f(a);
	b = f(b);

	multiset<ii> st;

	for (int i = 0; i < a.size(); i += 2) {
		if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
		st.emplace(a[i], a[i + 1]);
	}

	for (int i = 0; i < b.size(); i += 2) {
		if (b[i] > b[i + 1]) swap(b[i], b[i + 1]);
		auto it = st.find(ii(b[i], b[i + 1]));
		if (it == st.end()) {
			cout << "No" << endl;
			return;
		}
		st.erase(it);
	}

	cout << "Yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}