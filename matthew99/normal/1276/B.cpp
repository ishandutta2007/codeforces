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

const int maxn = 200100, maxm = 500100;

int n, m, a, b;
int fa[maxn + 5];
pair<int, int> ed[maxm + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

LL ans = 0;

bool hasa[maxn + 5], hasb[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b), --a, --b;
		REP(i, 0, n) fa[i] = i, hasa[i] = 0, hasb[i] = 0;
		REP(i, 0, m)
		{
			scanf("%d%d", &ed[i].x, &ed[i].y), --ed[i].x, --ed[i].y;
		}
		REP(i, 0, m)
			if (ed[i].x != a && ed[i].y != a && ed[i].x != b && ed[i].y != b)
			{
				fa[get(ed[i].x)] = get(ed[i].y);
			}
		REP(i, 0, m)
			if (ed[i].x == a || ed[i].y == a)
			{
				hasa[get(ed[i].x)] = 1;
				hasa[get(ed[i].y)] = 1;
			}
		REP(i, 0, m)
			if (ed[i].x == b || ed[i].y == b)
			{
				hasb[get(ed[i].x)] = 1;
				hasb[get(ed[i].y)] = 1;
			}

		int cnta = 0, cntb = 0;
		REP(i, 0, n) if (i != a && i != b)
		{
			if (!hasa[get(i)]) ++cnta;
			if (!hasb[get(i)]) ++cntb;
		}
		printf("%lld\n", (LL)cnta * cntb);
	}
	return 0;
}