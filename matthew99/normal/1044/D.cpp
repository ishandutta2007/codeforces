#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

map<int, int> fa, val;

int get(int x)
{
	if (!fa.count(x))
	{
		fa[x] = x;
		val[x] = 0;
		return x;
	}
	if (fa[x] == x) return x;
	int tmp = get(fa[x]);
	val[x] ^= val[fa[x]];
	fa[x] = tmp;
	return tmp;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int qn;
	int lst = 0;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, l, r, x;
		scanf("%d%d%d", &ty, &l, &r), l ^= lst, r ^= lst;
		if (l > r) swap(l, r);
		if (ty == 1) scanf("%d", &x), x ^= lst;
		++r;
		if (ty == 1)
		{
			int u = get(l), v = get(r);
			if (u == v) continue;
			fa[v] = u;
			val[v] ^= val[r] ^ val[l] ^ x;
		}
		else
		{
			int u = get(l), v = get(r);
			if (u != v) printf("-1\n"), lst = 1;
			else printf("%d\n", val[r] ^ val[l]), lst = val[r] ^ val[l];
		}
	}
	return 0;
}