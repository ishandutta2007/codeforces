#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++): *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int maxn = 1000000, maxm = 1000000, max0 = 10000000;

int deg[maxn + 5];
int Max[maxn + 5], dis[maxn + 5];

struct data
{
	int dis, x;

	data() { }
	data(int _dis, int _x): dis(_dis), x(_x) { }

	friend bool operator<(const data &x, const data &y) { return x.dis > y.dis; }

};

int tot = 0;
data q[max0 + 5];

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[maxm + 5];
int en = 0;
int st[maxn + 5];

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]);
	st[x] = en++;
}

int n, m;
int S, T;

bool vis[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(dis, oo, sizeof dis);
	memset(Max, 0, sizeof Max);
	memset(deg, 0, sizeof deg);
	memset(st, -1, sizeof st), en = 0;
	Read(n), Read(m);
	REP(i, 0, m)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		add_edge(y, x);
		++deg[x];
	}
	Read(S), Read(T), --S, --T;
	dis[T] = 0;
	q[tot++] = data(0, T);
	memset(vis, 0, sizeof vis);
	while (tot)
	{
		data x = q[0];
		pop_heap(q, q + (tot--));
		if (vis[x.x]) continue;
		vis[x.x] = 1;
		if (x.x == S)
		{
			printf("%d\n", x.dis);
			return 0;
		}
		for (int i = st[x.x]; i != -1; i = e[i].nxt)
		{
			int y = e[i].id;
			int tmp = dis[y];
			chkmax(Max[y], dis[x.x]);
			chkmin(dis[y], dis[x.x] + 1);
			if (!--deg[y]) chkmin(dis[y], Max[y]);
			if (dis[y] != tmp) q[tot++] = data(dis[y], y), push_heap(q, q + tot);
		}
	}
	printf("-1\n");
	return 0;
}