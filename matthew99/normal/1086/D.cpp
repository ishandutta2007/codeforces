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

const int maxn = 200100, maxq = 200100;

inline int stoi(const &s)
{
	if (s == 'R') return 0;
	if (s == 'P') return 1;
	if (s == 'S') return 2;
	assert(0);
	return -1;
}

int n, qn;
int a[maxn + 5];

set<int> all[3];
int fir[3], lst[3];

int fen[3][maxn + 5];

inline void add(int x, int y, int z)
{
	if (z == 1) all[x].insert(y);
	else all[x].erase(y);
	for (int i = y + 1; i <= n; i += i & -i)
		fen[x][i] += z;
}

inline int count(int x, int l, int r)
{
	if (l >= r) return 0;
	int ret = 0;
	for (int i = r; i > 0; i -= i & -i) ret += fen[x][i];
	for (int i = l; i > 0; i -= i & -i) ret -= fen[x][i];
	return ret;
}

inline int get_fir(int x)
{
	if (all[x].empty()) return n;
	return *all[x].begin();
}
 
inline int get_lst(int x)
{
	if (all[x].empty()) return -1;
	return *(--all[x].end());
}

inline int get_ans()
{
	int ret = 0;
	REP(i, 0, 3)
	{
		if (all[i].empty()) continue;
		if (!all[(i + 1) % 3].empty() && all[(i + 2) % 3].empty()) continue;

		ret += SZ(all[i]);
		int l0 = get_fir((i + 1) % 3) + 1, r0 = get_fir((i + 2) % 3);
		int l1 = get_lst((i + 2) % 3) + 1, r1 = get_lst((i + 1) % 3);

		if (l0 < r0) ret -= count(i, l0, r0);
		if (l1 < r1) ret -= count(i, l1, r1);
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[maxn + 5];
	scanf("%d%d", &n, &qn);
	scanf("%s", s);
	REP(i, 0, n) a[i] = stoi(s[i]);
	REP(i, 0, 3) all[i].clear();
	REP(i, 0, n) add(a[i], i, 1);
	printf("%d\n", get_ans());
	REP(i, 0, qn)
	{
		static char y[3];
		int x;
		scanf("%d%s", &x, y), --x;
		add(a[x], x, -1);
		a[x] = stoi(y[0]);
		add(a[x], x, 1);
		printf("%d\n", get_ans());
	}
	return 0;
}