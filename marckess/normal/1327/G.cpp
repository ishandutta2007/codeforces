#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005, SIG = 14;
const ll inf = 1e18;

struct AhoCorasick {
	int sz;
	vector<vi> sig, go;
	vi fail;
	vl cn;

	void init () {
		sig.assign(1, vi(SIG)), go.assign(1, vi(SIG, -1));
		fail.assign(1, 0), cn.assign(1, 0);
		sz = 0;
	}

	void insert (string &s, ll _cn) {
		int u = 0;

		for (int c : s) {
			c -= 'a';
			if (!sig[u][c]) {
				sig[u][c] = ++sz;
				sig.pb(vi(SIG)), go.pb(vi(SIG, -1));
				cn.pb(0), fail.pb(0);
			}
			u = sig[u][c];
		}

		cn[u] += _cn;
	}

	int get (int u, int c) {
		if (!u || sig[u][c]) return sig[u][c];
		if (go[u][c] == -1) go[u][c] = get(fail[u], c);
		return go[u][c];
	}

	void build () {
		queue<int> q;

		forn (i, SIG)
			if (sig[0][i])
				q.push(sig[0][i]);

		while (q.size()) {
			int u = q.front(); q.pop();

			for (int c = 0; c < SIG; c++) {
				int v = sig[u][c];

				if (v) {
					fail[v] = get(fail[u], c);
					cn[v] += cn[fail[v]];
					q.push(v);
				}
			}
		}
	}
}ac;

int k, c[MX];
ll res;
string t[MX], s;
vi q;
vector<vl> mem;
vector<bitset<1 << 14>> bs;

ll dp (int u, int j) {
	int i = __builtin_popcount(j);
	ll act = ac.cn[u];
	if (i == q.size()) return act;

	ll &res = mem[u][j];
	if (bs[u][j]) return res;
	bs[u][j] = 1;
	res = -inf;

	u = ac.get(u, i);
	for (int k = 0; k < 14; k++)
		if (!(j & (1 << k)))
			res = max(res, dp(ac.get(u, k), j | (1 << k)));
	res += act;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ac.init();

	cin >> k;
	forn (i, k) {
		cin >> t[i] >> c[i];
		ac.insert(t[i], c[i]);
	}
	cin >> s;

	int u = 0;
	ac.build();
	for (char c : s) {
		if (c == '?') u = 0;
		else {
			u = ac.get(u, c - 'a');
			res += ac.cn[u];
		}
	}

	forn (i, s.size())
		if (s[i] == '?')
			q.pb(i);
	ac.init();

	for (int i = 0; i < q.size(); i++)
		for (int j = 0; j < k; j++) {
			int ini = max(0, q[i] - (int)t[j].size() + 1);
			if (i) ini = max(ini, q[i - 1] + 1);

			for (int l = ini; l <= q[i] && l + t[j].size() <= s.size(); l++) {
				string v;

				for (int r = 0; r < t[j].size(); r++)
					if (s[l + r] == '?')
						v.pb(t[j][r]);
					else if (s[l + r] != t[j][r]) {
						v.clear();
						break;
					}
			
				if (v.size()) {
					string w;
					for (int r = 0; r < v.size(); r++)
						w.pb(i + r + 'a'), w.pb(v[r]);
					ac.insert(w, c[j]);
				}
			}
		}

	mem.assign(ac.sz + 1, vl(1 << 14));
	bs.resize(ac.sz + 1);

	ac.build();
	cout << res + dp(0, 0) << endl;

	return 0;
}