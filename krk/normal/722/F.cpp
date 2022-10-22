#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const int Maxk = 21;

int n, m, N;
vector <int> seq[Maxn];
int mx[Maxn];
vector <int> has[Maxn];
vector <vector <llll> > dp[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

void Euclid(ll a, ll &x, ll b, ll &y, ll &g)
{
	if (a == 0) { x = 0; y = 1; g = b; }
	else {
		ll xx, yy; Euclid(b % a, xx, a, yy, g);
		x = yy - b / a * xx; y = xx;
	}
}

ll Mult(ll a, ll b, ll c)
{
	if (b == 0) return 0;
	ll res = b % 2? a: 0;
	ll got = Mult(a, b / 2, c);
	res = (res + got + got) % c;
	return res;
}

bool Solve(ll a, ll c, ll b, ll d, ll L, ll &res)
{
	ll x, y, g; Euclid(c, x, d, y, g);
	if ((b - a) % g != 0) return false;
	res = (b - a) / g % L;
	if (res < 0) res += L;
	res = Mult(res, abs(x), L);
	if (x < 0) res = (L - res) % L;
	res = Mult(c, res, L);
	res = (res + a) % L;
	return true;
}

llll Join(const llll &p1, const llll &p2)
{
	if (p1.first < 0 || p2.first < 0) return llll(-1, 0);
	ll L = lcm(p1.second, p2.second);
	ll res;
	if (Solve(p1.first, p1.second, p2.first, p2.second, L, res))
		return llll(res, L);
	else return llll(-1, 0);
}

int Solve(int el)
{
	int ind = has[el].size() - 1, cand = dp[el].back().size() - 1;
	int tk = 0;
	llll cur = llll(1, 1);
	while (cand >= 0 && ind >= 0 && has[el][ind] == has[el].back() - tk) {
		if (cand >= dp[el][ind].size()) cand = dp[el][ind].size() - 1;
		llll nw = Join(cur, dp[el][ind][cand]);
		if (nw.first >= 0) {
			cur = nw; tk += 1 << cand;
			ind -= 1 << cand;
		}
		cand--;
	}
	return tk;
}

int main()
{
	scanf("%d %d", &n, &m); N = 2 * n;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		seq[i].resize(k);
		for (int j = 0; j < k; j++)
			scanf("%d", &seq[i][j]);
		seq[n + i].resize(k);
		for (int j = 0; j < k; j++)
			seq[n + i][j] = seq[i][(j + 1) % k];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < seq[i].size(); j++) {
			int el = seq[i][j];
			vector <llll> V; V.push_back(llll(j, seq[i].size()));
			for (int l = 1; (1 << l) - 1 <= dp[el].size() && has[el][dp[el].size() - (1 << l) + 1] == i - (1 << l) + 1; l++)
				V.push_back(Join(V[l - 1], dp[el][dp[el].size() - (1 << l - 1)][l - 1]));
			dp[el].push_back(V); has[el].push_back(i);
			mx[el] = max(mx[el], Solve(el));
		}
	for (int i = 1; i <= m; i++)
		printf("%d\n", min(mx[i], n));
	return 0;
}