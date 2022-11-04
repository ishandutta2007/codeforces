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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s;
int n, k, f = 1;
vvi res;
vi st;

void no () {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;
	
	while (f) {
		vi v;
		f = 0;
		forn (i, n - 1) {
			if (s[i] == 'R' && s[i + 1] == 'L') {
				f = 1;
				swap(s[i], s[i + 1]);
				i++;
				v.pb(i);
			}
		}
		if (v.size()) res.pb(v);
	}

	if (res.size() > k) no();

	while (res.size() && res.size() + st.size() < k) {
		int x = res.back().back();
		st.pb(x);
		res.back().pop_back();
		if (!res.back().size())
			res.pop_back();
	}

	if (res.size() + st.size() != k) no();

	for (vi &v : res) {
		cout << v.size();
		for (int r : v)
			cout << " " << r;
		cout << endl;
	}

	reverse(all(st));
	for (int x : st) {
		cout << 1 << " " << x << endl;
	}

	return 0;
}