#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct BIT {
	vi ft;

	BIT (int n) : ft(n+1) {}

	void update (int i, int k) {
		while (i < ft.size()) {
			ft[i] += k;
			i += i & -i;
		}
	}

	int query (int i) {
		int sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	}
};

int n, m, q[200005], l, r;
BIT ft(200005);
set<int> st[255];
string s;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q[i] = i;
		ft.update(i, 1);
	}

	cin >> s;
	for (int i = 0; i < n; i++)
		st[s[i]].insert(i+1);

	while (m--) {
		cin >> l >> r >> c;
		
		l = lower_bound(q, q+n+1, l, [&] (int a, int l) {
			return ft.query(a) < l;
		}) - q;

		r = lower_bound(q, q+n+1, r, [&] (int a, int r) {
			return ft.query(a) < r;
		}) - q;

		auto it = st[c].lower_bound(l);

		while (it != st[c].end() && *it <= r) {
			s[*it-1] = 0;
			ft.update(*it, -1);
			auto aux = it++;
			st[c].erase(aux);
		}
	}

	for (char c : s)
		if (c)
			cout << c;
	cout << endl;

	return 0;
}