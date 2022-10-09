#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m;
const int maxn = 100100;
vi v[maxn];
int LAST = 0, DL = 0;

int perm[maxn];
int dr[maxn];

inline void add(int p, int v) {
	for (; p < maxn; p += p & (-p)) dr[p] += v;
}
inline int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

inline int pytaj(int a, int b) {
	return get(b) - get(a - 1);
}
inline int query(int a, int b) {
	if (a <= b) return pytaj(a, b);
	return pytaj(a, n) + pytaj(1, b);
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		v[a].pb(i);
	}
	
	FOR(i, 1, 100000)
	{
		if (v[i].empty()) continue;
		int x = (int)v[i].size();
		for (int j = 0; j < (int)v[i].size(); ++j)
		{
			if (v[i][j] > LAST)
			{
				x = j;
				for (int k = j; k < (int)v[i].size(); ++k)
					perm[++DL] = v[i][k];
				break;
			}
		}
		for (int k = 0; k < x; ++k) perm[++DL] = v[i][k];
		LAST = perm[DL];
	}
	ll ret = 0;
	assert(DL == n);
	int OAST = 0;
	
	FOR(i, 1, n) add(i, 1);
	FOR(i, 1, n)
	{
		ret += query(OAST, perm[i]);
		add(perm[i], -1);
		OAST = perm[i];
	}
	cout << ret;
}