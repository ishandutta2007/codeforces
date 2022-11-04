#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;

inline void mul (ll &a, ll b) {
	a = a * b % mod;
}

inline void sum (ll &a, ll b) {
	a = (a + b) % mod;
}

struct ST {
	ll st[4*MX], ls[4*MX], lm[4*MX];

	ST () {
		memset(st, 0, sizeof(st));
		memset(ls, 0, sizeof(ls));
		fill(lm, lm+4*MX, 1);
	}

	void push (int i, int j, int pos) {
		mul(st[pos], lm[pos]);
		sum(st[pos], ls[pos] * (j - i + 1));

		if (i < j) {
			mul(lm[pos*2], lm[pos]);
			mul(ls[pos*2], lm[pos]);
			sum(ls[pos*2], ls[pos]);

			mul(lm[pos*2+1], lm[pos]);
			mul(ls[pos*2+1], lm[pos]);
			sum(ls[pos*2+1], ls[pos]);
		}

		ls[pos] = 0;
		lm[pos] = 1;
	}

	void update (int i, int j, int pos, int a, int b, int m, int s) {
		if (lm[pos] != 1 || ls[pos]) push(i, j, pos);
		if (b < i || j < a) return;

		if (a <= i && j <= b) {
			lm[pos] = m;
			ls[pos] = s;
			push(i, j, pos);
			return;
		}

		int mit = (i+j)/2;
		update(i, mit, pos*2, a, b, m, s);
		update(mit+1, j, pos*2+1, a, b, m, s);
		st[pos] = (st[pos*2] + st[pos*2+1]) % mod;
	}

	ll query (int i, int j, int pos, int a, int b) {
		if (lm[pos] != 1 || ls[pos]) push(i, j, pos);
		if (b < i || j < a) return 0;
		if (a <= i && j <= b) return st[pos];

		int m = (i+j)/2;
		return
			(query(i, m, pos*2, a, b) +
			query(m+1, j, pos*2+1, a, b)) % mod;
	}
}st;

int n, q, t, l, r, x;
set<ii> s[MX];

void add (set<ii> &s) {
	auto it = s.lower_bound({l, -1});
	int ant = l;

	if (it != s.begin()) {
		auto aux = it;
		aux--;
		if (aux->se >= l) it = aux;
	}

	while (it != s.end() && it->fi <= r) {
		if (ant < it->fi) st.update(1, n, 1, ant, it->fi-1, 1, 1);
		st.update(1, n, 1, max(l, it->fi), min(r, it->se), 2, 0);
		ant = it->se+1;

		l = min(l, it->fi);
		r = max(r, it->se);

		auto aux = it;
		it++;
		s.erase(aux);
	}

	if (ant <= r)
		st.update(1, n, 1, ant, r, 1, 1);

	s.emplace(l, r);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	while (q--) {
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			add(s[x]);
		} else {
			cout << st.query(1, n, 1, l, r) << endl;
		}
	}

	return 0;
}