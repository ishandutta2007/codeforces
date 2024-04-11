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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000, maxq = 1000;
const int maxm = 500000;

struct edge
{
	int x, y, w, id;

	edge() { }
	edge(int _x, int _y, int _w): x(_x), y(_y), w(_w) { }

	friend bool operator<(const edge &x, const edge &y) { return x.w > y.w; }

};

int n, m, qn;
edge e[maxm + 5];

int fa[maxn + 5], col[maxn + 5];

int get(int x) 
{ 
	if (fa[x] == x) return x;
	int tmp = get(fa[x]);
	col[x] ^= col[fa[x]];
	return fa[x] = tmp;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w), --e[i].x, --e[i].y, e[i].id = i;
	sort(e, e + m);
	REP(i, 0, qn)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u;
		REP(j, 0, n) fa[j] = j, col[j] = 0;
		int ret = -1;
		REP(j, 0, m) if (e[j].id >= u && e[j].id < v)
		{
			int x = e[j].x, y = e[j].y;
			if (get(x) != get(y))
			{
				int u = get(x), v = get(y);
				col[u] ^= col[x] ^ col[y] ^ 1;
				fa[u] = v;
			}
			else if (col[x] == col[y]) { ret = e[j].w; break; }
		}
		printf("%d\n", ret);
	}
	return 0;
}