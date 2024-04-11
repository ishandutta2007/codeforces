#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, md = 1e9 + 7, inv2 = (md + 1) >> 1;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += md;
	return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

map <pii, int> incyc;
vector <int> a[N], b[N];
int pw[N], big[N], low[N], dfn[N], st[N], u[N], v[N], sum[N];
int n, m, A, B, C, D, AA, BB, CC, AB, AC, BC, DD, cnt, top, newn, cyc;

void tarjan(int u, int fa) {
	low[u] = dfn[u] = ++cnt; st[++top] = u;
	for (auto v : a[u]) {
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++newn;
				int tmp = -1, las = u;
				vector <pii> pairs;
				while (tmp != v) {
					tmp = st[top--];
					// incyc[make_pair(tmp, las)] = incyc[make_pair(las, tmp)] = 1;
					pairs.emplace_back(tmp, las);
					b[newn].push_back(tmp);
					b[tmp].push_back(newn);
					las = tmp;
				}
				// incyc[make_pair(u, las)] = incyc[make_pair(las, u)] = 1;
				pairs.emplace_back(u, las);
				b[u].push_back(newn);
				b[newn].push_back(u);
				if (b[newn].size() > 2) {
					for (auto i : pairs) incyc[i] = incyc[make_pair(i.second, i.first)] = pw[b[newn].size()];
				}
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	read(n); read(m); newn = n;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], inv2);
	for (int i = 1; i <= m; i++) {
		read(u[i]); read(v[i]);
		a[u[i]].push_back(v[i]);
		a[v[i]].push_back(u[i]);
	}
	tarjan(1, 0);
	A = mul(n, pw[1]);
	B = mul(m, pw[2]);
	for (int i = n + 1; i <= newn; i++) if (b[i].size() > 2) C = add(C, pw[b[i].size()]);
	D = add(sub(A, B), C);
	// cout << A << " " << B << " " << C << " " << D << endl;
	AA = add(A, mul(1ll * n * (n - 1) % md, pw[2]));
	for (int i = 1; i <= n; i++) AB = add(AB, add(mul(a[i].size(), pw[2]), mul(m - a[i].size(), pw[3])));
	for (int i = n + 1; i <= newn; i++) if (b[i].size() > 2) cyc = add(cyc, pw[b[i].size()]);
	for (int i = 1; i <= n; i++) {
		for (auto v : b[i]) if (b[v].size() > 2) sum[i] = add(sum[i], pw[b[v].size()]);
		for (auto v : b[i]) if (b[v].size() > 2) sum[v] = add(sum[v], sub(sum[i], pw[b[v].size()]));
		AC = add(AC, add(sum[i], mul(sub(cyc, sum[i]), pw[1])));
	}
	for (int i = 1; i <= m; i++) {
		int tmp = a[u[i]].size() + a[v[i]].size() - 2;
		BB = add(BB, add(mul(tmp, pw[3]), mul(m - tmp - 1, pw[4])));
	}
	BB = add(B, BB);
	for (int i = 1; i <= m; i++) {
		int sum1 = add(sum[u[i]], sum[v[i]]), sum2 = 0;
		if (incyc.count(make_pair(u[i], v[i]))) {
			sum2 = incyc[make_pair(u[i], v[i])];
			sum1 = sub(sum1, mul(sum2, 2));
		}
		BC = add(BC, sum2);
		BC = add(BC, mul(sum1, pw[1]));
		BC = add(BC, mul(sub(cyc, add(sum1, sum2)), pw[2]));
	}
	CC = C;
	for (int i = n + 1; i <= newn; i++) {
		if (b[i].size() <= 2) continue;
		CC = add(CC, mul(sum[i], pw[b[i].size() - 1]));
		CC = add(CC, mul(sub(cyc, add(sum[i], pw[b[i].size()])), pw[b[i].size()]));
		// cout << sub(cyc, add(sum[i], pw[b[i].size()])) << endl;
		// cout << cyc << " " << sum[i] << " " << pw[b[i].size()] << endl;
	}
	DD = ((1ll * AA + BB + CC - 2 * AB - 2 * BC + 2 * AC) % md + md) % md;
	// cout << AA << " " << AB << " " << AC << " " << BB << " " << BC << " " << CC << " " << DD << endl;
	// cout << add(pw[2], pw[4]) << endl;
	print(sub(add(DD, mul(D, D)), mul(2, mul(D, D))), '\n');
    return 0;
}