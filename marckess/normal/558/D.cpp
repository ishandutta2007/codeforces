#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int q;
ll h, l, r, g, k;
set<ii> st;

void eliExt (ll a, ll b) {
	auto it = st.begin();

	while (it != st.end() && it->fi < a) {
		auto aux = it;
		it++;

		if (aux->se < a) {
			st.erase(aux);
		} else {
			ll temp = aux->se;
			st.erase(aux);
			st.emplace(a, temp);
		}
	}

	it = st.end();
	if (it == st.begin()) return;
	it--;
 
	while (it->se > b) {
		auto aux = it;
		bool f = 0;

		if (it != st.begin()) it--;
		else f = 1;

		if (aux->fi > b) {
			st.erase(aux);
		} else {
			ll temp = aux->fi;
			st.erase(aux);
			st.emplace(temp, b);
		}

		if (f) break;
	}
}

void eliCen (ll a, ll b) {
	auto it = st.lower_bound({a+1, -1});

	if (it != st.begin())
		it--;

	while (it != st.end() && it->fi <= b) {
		auto aux = it;
		it++;

		if (a <= aux->fi && aux->se <= b) {
			st.erase(aux);
		} else if (aux->fi <= a-1 && b+1 <= aux->se) {
			ll ta = aux->fi;
			ll tb = aux->se;
			st.erase(aux);
			st.emplace(ta, a-1);
			st.emplace(b+1, tb);
		} else if (aux->fi <= a-1 && a-1 <= aux->se) {
			ll temp = aux->fi;
			st.erase(aux);
			st.emplace(temp, a-1);
		} else if (aux->fi <= b+1 && b+1 <= aux->se) {
			ll temp = aux->se;
			st.erase(aux);
			st.emplace(b+1, temp);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> h >> q;

	st.emplace(1ll << (h - 1), (1ll << h) - 1);

	while (q--) {
		cin >> g >> l >> r >> k;

		ll a = l * (1ll << (h - g));
		ll b = (r + 1) * (1ll << (h - g)) - 1;

		if (k)
			eliExt(a, b);
		else
			eliCen(a, b);
	}

	if (st.empty())
		cout << "Game cheated!" << endl;
	else if (st.size() > 1)
		cout << "Data not sufficient!" << endl;
	else if (st.begin()->fi == st.begin()->se)
		cout << st.begin()->fi << endl;
	else
		cout << "Data not sufficient!" << endl;

	return 0;
}