#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005, p = 3;
int mod[] = {
	1000000007,
	1000000009,
	1000000021,
	1000000087,
	1000000861,
	1000004329,
};
ll b[p][MX];

struct Hsh {
	ll hsh[p][MX];
	int x[MX], sz;

	Hsh() : sz(0) {}

	void insert (int c) {
		for (int i = 0; i < p; i++)
			hsh[i][sz] = (c + b[i][0] * (sz ? hsh[i][sz-1] : 0)) % mod[i];
		x[sz] = c ^ (sz ? x[sz-1] : 0);
		sz++;
	}

	ll get (int l, int r, int i) {
		if (i == -1) return x[r] ^ (l ? x[l-1] : 0);
		return MOD(hsh[i][r] - (l ? hsh[i][l-1] * b[i][r - l] : 0), mod[i]);
	}

	bool same (int a1, int b1, int a2, int b2) {
		if (get(a1, b1, -1) != get(a2, b2, -1)) return 0;
		for (int i = 0; i < p; i++)
			if (get(a1, b1, i) != get(a2, b2, i))
				return 0;
		return 1;
	}
}h;
string s, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	srand(time(0));
	random_shuffle(mod, mod + 6);
	for (int i = 0; i < p; i++) {
		b[i][0] = (1ll * rand() * rand() + rand()) % mod[i];
		for (int j = 1; j < MX; j++)
			b[i][j] = b[i][j-1] * b[i][0] % mod[i];
	}

	cin >> s;
	while (cin >> s) {
		for (char c : s)
			h.insert(c);

		int mx = 0;
		for (int i = 0; i < min(res.size(), s.size()); i++)
			if (h.same(res.size(), res.size() + i, res.size() - i - 1, res.size() - 1))
				mx = i + 1;

		h.sz = res.size();
		for (int i = mx; i < s.size(); i++) {
			h.insert(s[i]);
			res.push_back(s[i]);
		}
	}

	cout << res << endl;
 
	return 0;
}