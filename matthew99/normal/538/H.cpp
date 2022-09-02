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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxabs = 1e9;
const int maxn = 100000;

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

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	int Min;
	int label;
 
	node(): Min(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo;
		REP(i, 0, 2) 
			if (c[i]) chkmin(Min, c[i]->Min);
			else Min = 0;
	}

	void flag_label(int _label)
	{
		label += _label;
		chkmin(label, oo);
		Min += _label;
		chkmin(Min, oo);
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) 
			{
				if (!c[i]) c[i] = newnode();
				c[i]->flag_label(label);
			}
			label = 0;
		}
	}

	inline int get_Min() { return this ? Min : 0; }
 
};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}
 
node *rt;
 
int seg_x, seg_y, seg_z;
 
void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

inline bool seg_add(int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, maxabs + 1);
	return 1;
}

int tl, tr;
int n, m;
pair<int, int> a[maxn + 5];

int fa[maxn + 5];
bool ty[maxn + 5];

vector<int> all[maxn + 5];

inline int get(int x)
{
	if (fa[x] == x) return x;
	int tmp = get(fa[x]);
	ty[x] ^= ty[fa[x]];
	return fa[x] = tmp;
}

pair<int, int> interv[maxn + 5];

inline bool cmpl(int x, int y) { return interv[x].x < interv[y].x; }
inline bool cmpr(int x, int y) { return interv[x].y < interv[y].y; }

inline int find(node *rt, int l, int r)
{
	if (!rt) return l;
	if (r - l <= 1) return l;
	int mid = (l + r) >> 1;
	rt->push_down();
	if (!rt->c[0]->get_Min()) return find(rt->c[0], l, mid);
	return find(rt->c[1], mid, r);	
}

inline int query(node *rt, int l, int r)
{
	if (!rt) return 0;
	if (r - l <= 1) return rt->Min;
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) return query(rt->c[0], l, mid);
	return query(rt->c[1], mid, r);
}

inline int seg_query(int x)
{
	seg_x = x;
	return query(rt, 0, maxabs + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(tl), Read(tr), ++tr;
	Read(n), Read(m);
	REP(i, 0, n) Read(a[i].x), Read(a[i].y), ++a[i].y;
	REP(i, 0, n) fa[i] = i, ty[i] = 0;
	REP(i, 0, m)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		int u = get(x), v = get(y);
		if (u == v)
		{
			if (ty[x] == ty[y]) EXIT("IMPOSSIBLE\n");
		}
		else fa[u] = v, ty[u] = ty[x] == ty[y];
	}
	REP(i, 0, n) all[get(i)].pb(i);
	static int posl[maxn + 5], posr[maxn + 5];
	int N = 0;
	vector<int> X;
	int cnt = 0;
	REP(i, 0, n) 
		if (fa[i] == i)
		{
			++cnt;
			int L[2], R[2];
			memset(L, 0, sizeof L);
			memset(R, oo, sizeof R);
			for (auto it : all[i])
			{
				chkmax(L[ty[it]], a[it].x);
				chkmin(R[ty[it]], a[it].y);
			}
			REP(j, 0, 2) if (L[j] >= R[j]) EXIT("IMPOSSIBLE\n");
			if (L[0] > L[1]) swap(L[0], L[1]), swap(R[0], R[1]);
			seg_add(0, L[0], n + 1);
			seg_add(R[0], L[1], n + 1);
			seg_add(max(R[0], R[1]), maxabs + 1, n + 1);
			REP(j, 0, 2) if (L[j] > 0 || R[j] < oo) 
			{
				interv[N++] = mp(L[j], R[j]), seg_add(0, L[j], 1), seg_add(R[j], maxabs + 1, 1), X.pb(L[j]);
				if (R[j] <= tl) X.pb(tl - R[j] + 1);
			}
		}
	sort(ALL(X));
	REP(i, 0, N) posl[i] = posr[i] = i;
	sort(posl, posl + N, cmpl);
	sort(posr, posr + N, cmpr);
	int i = 0, j = 0;
	int p[2] = {-1, -1};
	for (auto now : X)
	{
		while (i < N && interv[posl[i]].x <= now) seg_add(0, interv[posl[i]].x, -1), seg_add(interv[posl[i]].y, maxabs + 1, -1), ++i;
		while (j < N && interv[posr[j]].y <= now) seg_add(0, interv[posr[j]].x, 1), seg_add(interv[posr[j]].y, maxabs + 1, 1), ++j;
		if (!rt->Min && seg_query(now) <= n)
		{
			seg_add(0, tl - now, 1);
			seg_add(tr - now, maxabs + 1, 1);
			if (!rt->Min)
			{
				p[0] = now;
				p[1] = find(rt, 0, maxabs + 1);
				break;
			}
			seg_add(0, tl - now, -1);
			seg_add(tr - now, maxabs + 1, -1);
		}
	}
	if (p[0] == -1) EXIT("IMPOSSIBLE\n");
	static int ans[maxn + 5];
	printf("POSSIBLE\n");
	printf("%d %d\n", p[0], p[1]);
	REP(i, 0, n)
		if (fa[i] == i)
		{
			bool flag = 0;
			for (auto it : all[i])
			{
				if (a[it].x > p[ty[it]] || a[it].y < p[ty[it]])
				{
					flag = 1;
					break;
				}
			}
			for (auto it : all[i]) ans[it] = 1 + (ty[it] ^ flag);
		}
	REP(i, 0, n) printf("%d", ans[i]);
	return 0;
}