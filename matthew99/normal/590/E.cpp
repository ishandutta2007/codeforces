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
 
const int maxn = 750;
const int max0 = 10000000;

int get(char c) { return c == 'b'; }

int id;
 
struct node
{
	int id;
	bool p;
	node *go[2];
	node *f;
	node *lst;
 
	node(): id(-1), f(NULL) { memset(go, 0, sizeof go); }
};
 
node nd[max0 + 5];
int cur = 0;
 
node *p[maxn + 5];
 
node *rt;
 
node *add(node *&rt, char *s)
{
	node **tmp = &rt;
	for (int i = 0; ; ++i)
	{
		node *&a = *tmp;
		if (!a) a = nd + (cur++), a->p = i ? get(s[i - 1]) : 0;
		if (s[i]) tmp = &a->go[get(s[i])];
		else break;
	}
	return *tmp;
}

int n;

bool f[maxn + 5][maxn + 5];

int link[maxn + 5];
bool vis[maxn + 5];

inline bool find(int x)
{
	REP(y, 0, n)
		if (f[x][y] && !vis[y])
		{
			vis[y] = 1;
			if (link[y] == -1 || find(link[y]))
			{
				link[y] = x;
				return 1;
			}
		}
	return 0;
}

int l[maxn + 5], r[maxn + 5];

int deg[maxn + 5];

int pos[maxn + 5];
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	rt = nd + (cur++);
	static char s[max0 + 5];
	scanf("%d", &n);
	int tot_len = 0;
	int m = 0;
	REP(i, 0, n)
	{
		scanf("%s", s + tot_len);
		pos[m] = i;
		l[m] = tot_len;
		p[m] = add(rt, s + tot_len);
		tot_len = r[m] = tot_len + strlen(s + tot_len);
		if (p[m]->id == -1)
		{
			p[m]->id = m;
			++m;
		}
	}
	n = m;
	static node *q[max0 + 5];
	int head = 0, rear = 0;
	q[rear++] = rt;
	rt->f = rt;
	rt->lst = rt;
	while (head != rear)
	{
		node *x = q[head++];
		if (x->id != -1) x->lst = x;
		else x->lst = x->f->lst;
		for (int i = 0; i < 2; ++i)
		{
			node *y = x->go[i];
			if (!y) 
			{
				x->go[i] = x == rt ? rt : x->f->go[i];
			}
			else
			{
				q[rear++] = y;
				y->f = x == rt ? x : x->f->go[y->p];
			}
		}
	}
	REP(i, 0, n)
	{
		node *now = rt;
		REP(j, l[i], r[i])
		{
			now = now->go[get(s[j])];
			if (j == r[i] - 1) now = now->f;
			assert(now);
			assert(now->lst);
			if (now->lst->id >= 0) f[i][now->lst->id] = 1;
		}
	}
	REP(k, 0, n)
		REP(i, 0, n)
			REP(j, 0, n)
				if (f[i][k] && f[k][j]) f[i][j] = 1;
	memset(link, -1, sizeof link);
	int ans = 0;
	REP(i, 0, n)
	{
		memset(vis, 0, sizeof vis);
		if (!find(i)) ++ans;
	}
	vector<vector<int> > all;
	memset(deg, 0, sizeof deg);
	REP(i, 0, n) if (link[i] != -1) ++deg[link[i]];
	REP(i, 0, n)
	{
		if (deg[i]) continue;
		int u = i;
		vector<int> tmp;
		while (u != -1)
		{
			tmp.pb(u);
			u = link[u];
		}
		all.pb(tmp);
	}
	printf("%d\n", ans);
	static int ret[maxn + 5] = {0};
	int alln = SZ(all);
	memset(ret, 0, sizeof ret);
	{
		static int q[maxn + 5];
		static bool vis[maxn + 5] = {0};
		memset(vis, 0, sizeof vis);
		int head = 0, rear = 0;
		REP(a, 0, alln) REP(b, 0, alln)
			if (!vis[b] && a != b && f[all[a][ret[a]]][all[b][ret[b]]]) q[rear++] = b, vis[b] = 1;
		while (head != rear)
		{
			int x = q[head++];
			if (head >= maxn + 1) head -= maxn + 1;
			vis[x] = 0;
			REP(y, 0, alln) 
			{
				while (f[all[y][ret[y]]][all[x][ret[x]]]) ++ret[x];
			}
			REP(y, 0, alln) if (!vis[y] && f[all[x][ret[x]]][all[y][ret[y]]]) 
			{
				q[rear++] = y, vis[y] = 1;
				if (rear >= maxn + 1) rear -= maxn + 1;
			}
		}
	}
	REP(i, 0, alln)
	{
		printf("%d ", pos[all[i][ret[i]]] + 1);
	}
	return 0;
}