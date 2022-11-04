#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

set<ii> st;
int n, q, acu, l, r, k;

int ins () {
	int res = 0;

	auto it = st.upper_bound(ii(l, -1));
	it--;

	while (it != st.end() && it->fi <= r) {
		if (!(it->fi > r || it->se < l)) {
			auto aux = it;
			res -= it->se - it->fi + 1;
			l = min(l, it->fi);
			r = max(r, it->se);

			it++;
			st.erase(aux);
		} else {
			it++;
		}
	}

	st.emplace(l, r);
	res += r - l + 1;
	return res;
}

int del () {
	int res = 0;

	auto it = st.upper_bound(ii(l, -1));
	it--;

	while (it != st.end() && it->fi <= r) {
		if (!(it->fi > r || it->se < l)) {
			auto aux = it;
			bool f = 1;
			res -= it->se - it->fi + 1;
			
			if (it->fi <= l-1 && l <= it->se) {
				st.emplace(it->fi, l-1);
				res += l - it->fi;
				f = 0;
			}
			if (r+1 <= it->se && r >= it->fi) {
				st.emplace(r+1, it->se);
				res += it->se - r;
				f = 0;
			}

			it++;
			st.erase(aux);
		} else {
			it++;
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;

	st.emplace(0, 0);
	st.emplace(1, n);
	acu = n;

	while (q--) {
		cin >> l >> r >> k;

		if (k == 1)
			acu += del();
		else
			acu += ins();

		cout << acu << endl;
	}

	return 0;
}