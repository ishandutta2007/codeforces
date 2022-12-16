#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef deque <int> vi;
template <int mod>
class mint {
	public:
		int x;
		mint() : x(0) {}
		mint(int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
		friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
		friend mint operator * (mint a, mint b) { return a.x = 1ll * a.x * b.x % mod, a; }
		template <typename __Tp> friend mint operator ^ (mint a, __Tp p) {
			mint ans = 1;
			while (p) {
				if (p & 1) ans = ans * a;
				a = a * a, p >>= 1;
			}
			return ans;
		}
		friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }
		friend mint & operator += (mint &a, mint b) { return a = a + b; }
		friend mint & operator -= (mint &a, mint b) { return a = a - b; }
		friend mint & operator *= (mint &a, mint b) { return a = a * b; }
		friend mint & operator /= (mint &a, mint b) { return a = a / b; }
		friend mint & operator ^= (mint &a, int b) { return a = a ^ b; }

		mint & operator ++ () { return *this += 1; }
		const mint operator ++ (int) { mint t = *this; *this += 1; return t; }
		mint & operator -- () { return *this -= 1; }
		const mint operator -- (int) { mint t = *this; *this -= 1; return t; }

		friend bool operator == (mint a, mint b) { return a.x == b.x; }
		friend bool operator != (mint a, mint b) { return a.x != b.x; }
};

const int maxn = 5e5 + 10;
typedef mint <998244353> mi;
int n1,n2,q,m,bel[maxn],tot;
vi chain[maxn];
int lp[maxn],rp[maxn];
mi hs[maxn][2],pw2[maxn],sum;

void link(int x, int y, int i) {
	y += n1;
	if (bel[y]) swap(x, y);
	if (!bel[x]) {
		chain[++tot].push_back(i);
		bel[lp[tot] = x] = bel[rp[tot] = y] = tot;
		hs[tot][0] = pw2[i], hs[tot][1] = 0;
		sum += hs[tot][0]; return;
	}
	if (!bel[y]) {
		int k = bel[x];
		sum -= hs[k][0];
		if (x == lp[k]) {
			chain[k].push_front(i);
			swap(hs[k][0], hs[k][1]), hs[k][0] += pw2[i];
			bel[x] = 0, bel[lp[k] = y] = k;
		}
		else {
			chain[k].push_back(i);
			hs[k][(chain[k].size() & 1) ^ 1] += pw2[i];
			bel[x] = 0, bel[rp[k] = y] = k;
		}
		sum += hs[k][0]; return;
	}
	if (bel[x] == bel[y]) {
		int k = bel[x];
		sum -= hs[k][0];
		chain[k].push_back(i);
		hs[k][1] += pw2[i];
		bel[x] = bel[y] = 0;
		sum += hs[k][0];
		return;
	}
	int p = bel[x], q = bel[y];
	sum -= hs[p][0] + hs[q][0];
	if (chain[p].size() < chain[q].size()) swap(x, y), swap(p, q);
	auto ins = [&](int id) {
		if (x == lp[p]) {
			chain[p].push_front(id);
			swap(hs[p][0], hs[p][1]), hs[p][0] += pw2[id];
		}
		else {
			chain[p].push_back(id);
			hs[p][(chain[p].size() & 1) ^ 1] += pw2[id];
		}
	};
	ins(i);
	while (!chain[q].empty()) {
		if (y == lp[q]) ins(chain[q].front()), chain[q].pop_front();
		else ins(chain[q].back()), chain[q].pop_back();
	}
	bel[x] = bel[y] = 0;
	if (y == lp[q]) y = rp[q];
	else y = lp[q];
	if (x == lp[p]) lp[p] = y;
	else rp[p] = y;
	bel[lp[p]] = bel[rp[p]] = p;
	sum += hs[p][0];
}

void print_solution() {
	vi tmp;
	for (int i = 1; i <= tot; ++i) if (!chain[i].empty())
		for (int j = 0; j < (int) chain[i].size(); j += 2) tmp.push_back(chain[i][j]);
	sort(tmp.begin(), tmp.end());
	cout << tmp.size();
	for (int i : tmp) cout << ' ' << i;
	cout << endl;
	// for (int i = 1; i <= tot; ++i) if (!chain[i].empty()) {
	// 	cout << "chain " << i << " : (" << lp[i] << ", " << rp[i] << ")";
	// 	for (int j : chain[i]) cout << " " << j;
	// 	cout << endl;
	// }
}

int main() {
	pw2[0] = 1;
	for (int i = 1; i <= 400000; ++i) pw2[i] = pw2[i - 1] * 2;
	cin >> n1 >> n2 >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y;
		link(x, y, i);
	}
	cin >> q;
	for (int i = 1, idx = m; i <= q; ++i) {
		int op, x, y; cin >> op;
		if (op == 1) cin >> x >> y, link(x, y, ++idx), cout << sum.x << endl;
		else print_solution();
	}
	return 0;
}