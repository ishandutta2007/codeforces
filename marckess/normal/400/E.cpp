#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define nt(n) (ll(n) * ((n) + 1) / 2)

int n, m, a[100005], len[20][100005], p, v;
set<int> st[20];
ll res = 0;

void init () {
	for (int i = 0; i < 20; i++) {
		fill(len[i], len[i]+n, 0);
	}
}

void insert (int x, int y) {
	int p = (1 << x);
	set<int> &s = st[x];
	auto it = s.lower_bound(y);

	if (it != s.end() && y == *it - len[x][*it]) {
		res -= nt(len[x][*it]) * p;
		len[x][*it]++;
		res += nt(len[x][*it]) * p;
	} else {
		s.insert(y);
		len[x][y] = 1;
		res += p;
	}

	if ((it = s.lower_bound(y)) != s.begin()) {
		auto jt = it;
		jt--;
		if (*jt + 1 == y) {
			res -= nt(len[x][*jt]) * p;
			res -= nt(len[x][*it]) * p;

			len[x][*it] += len[x][*jt];
			res += nt(len[x][*it]) * p;

			s.erase(jt);
		}
	}
}

void erase (int x, int y) {
	int p = (1 << x);
	set<int> &s = st[x];
	auto it = s.lower_bound(y);

	if (*it == y) {
		if (len[x][y] == 1) {
			res -= p;
			s.erase(it);
		} else {
			res -= nt(len[x][y]) * p;
			len[x][y-1] = len[x][y] - 1;
			res += nt(len[x][y-1]) * p;

			s.insert(y-1);
			s.erase(it);
		}
	} else if (y == *it - len[x][*it] + 1) {
		res -= nt(len[x][*it]) * p;
		len[x][*it]--;
		res += nt(len[x][*it]) * p;
	} else {
		res -= nt(len[x][*it]) * p;

		len[x][y-1] = len[x][*it] - (*it - y + 1); 
		len[x][*it] -= len[x][y-1] + 1;

		res += nt(len[x][*it]) * p;
		res += nt(len[x][y-1]) * p;

		s.insert(y-1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	init();

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	
		for (int j = 0, k = 1; j < 18; j++, k *= 2) {
			if (a[i] & k) {
				insert(j, i);
			}
		}
	}

	while (m--) {
		cin >> p >> v;

		p--;

		for (int j = 0, k = 1; j < 18; j++, k *= 2) {
			if ((a[p] & k) > (v & k)) {
				erase(j, p);
			} else if ((a[p] & k) < (v & k)) {
				insert(j, p);
			}
		}

		a[p] = v;

		cout << res << endl;
	}

	return 0;
}