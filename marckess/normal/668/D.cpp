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

const int MX = 100005, MAX = 1e9;

struct ST {
	ST *izq, *der;
	int s;

	ST () {
		izq = der = 0;
		s = 0;
	}

	void update (int i, int j, int x, int k) {
		if (i == j) {
			s += k;
			return;
		}

		int m = (i + j) / 2;

		if (x <= m) {
			if (!izq) izq = new ST();
			
			s -= izq->s;
			izq->update(i, m, x, k);
			s += izq->s;
		} else {
			if (!der) der = new ST();

			s -= der->s;
			der->update(m + 1, j, x, k);
			s += der->s;
		}
	}

	int query (int i, int j, int x) {
		if (x < i) return 0;

		if (j <= x) return s;

		int res = 0;
		int m = (i + j) / 2;

		if (izq) res += izq->query(i, m, x);
		if (der) res += der->query(m + 1, j, x);

		return res;
	}
}st[MX];

int n;
map<int, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (_, n) {
		int a, t, x;
		cin >> a >> t >> x;

		if (!mp.count(x)) {
			int sz = mp.size();
			mp[x] = sz;
		}

		x = mp[x];

		if (a == 1) {
			st[x].update(1, MAX, t, 1);
		} else if (a == 2) {
			st[x].update(1, MAX, t, -1);
		} else {
			cout << st[x].query(1, MAX, t) << endl;
		}
	}

	return 0;
}