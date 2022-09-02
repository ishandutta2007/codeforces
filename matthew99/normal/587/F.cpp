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

const int max0 = 100000, max1 = 320, max2 = 320;

struct data
{
	int l, r, p;
	
	data() { }
	data(const int &_l, const int &_r, const int &_p): l(_l), r(_r), p(_p) { }

};

struct node
{
	int p;
	node *go[26];
	node *f;
	node(): f(NULL) { memset(go, 0, sizeof go); }

	vector<data> allq;
	vector<int> allp;

};

node nd[max0 + 5];
int cur = 0;

vector<node*> child[max0 + 5];

node *p[max0 + 5];
node *rt;

int dfn[max0 + 5], End[max0 + 5];
int dfn_cnt = 0;

int n, qn;

vector<node*> path[max0 + 5];

node *add(node *&rt, char *s, vector<node*> &path)
{
	if (rt == NULL) rt = nd + (cur++);
	path.pb(rt);
	if (!s[0]) return rt;
	node *tmp = add(rt->go[s[0] - 'a'], s + 1, path);
	rt->go[s[0] - 'a']->p = s[0] - 'a';
	return tmp;
}

void dfs(node *rt)
{
	int x = rt - nd;
	dfn[x] = dfn_cnt++;
	for (auto y : child[rt - nd]) dfs(y);
	End[x] = dfn_cnt;
}

int c[max0 + 5];

int pos[max0 + 5];

vector<data> all[max0 + 5];

LL ans[max0 + 5];

int tot[max0 + 5], pre[max0 + 5];

void add(const int &x, const int &y)
{
	int tmp = x / max2 + 1;
	REP(i, x, min(n + 1, tmp * max2)) pre[i] += y;
	for (int i = tmp * max2; i <= n; i += max2) tot[i] += y; 
}

int query(const int &x) { return tot[x - x % max2] + pre[x]; }

void dfs0(node *rt)
{
	for (auto y : rt->allp) add(y + 1, 1);
	for (auto y : rt->allq) ans[y.p] += query(y.r) - query(y.l);
	for (auto y : child[rt - nd]) dfs0(y);
	for (auto y : rt->allp) add(y + 1, -1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	rt = nd + (cur++);
	static char s[max0 + 5];
	scanf("%d%d", &n, &qn);
	REP(i, 0, n)
	{
		scanf("%s", s);
		(p[i] = add(rt, s, path[i]))->allp.pb(i);
	}

    static node *q[max0 + 5];
    int head = 0, rear = 0;
    q[rear++] = rt;
    rt->f = rt;
    while (head != rear)
    {
        node *x = q[head++];
        for (int i = 0; i < 26; ++i)
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
    REP(i, 1, rear) child[q[i]->f - nd].pb(q[i]);
	dfs(rt);

	REP(i, 0, qn)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --w;
		auto tmp = data(u, v, i);
		if (SZ(path[w]) > max1) all[w].pb(tmp);
		else for (auto lyc : path[w]) lyc->allq.pb(tmp);
	}

	memset(pos, -1, sizeof pos);

	REP(i, 0, n)
	{
		if (SZ(path[i]) > max1 && SZ(all[i]))
		{
			memset(c, 0, sizeof c);
			for (auto lyc : path[i]) ++c[dfn[lyc - nd] + 1];
			REP(j, 0, cur) c[j + 1] += c[j];
			static LL sum[max0 + 5];
			REP(j, 0, n) sum[j + 1] = c[End[p[j] - nd]] - c[dfn[p[j] - nd]];
			sum[0] = 0;
			REP(j, 0, n) sum[j + 1] += sum[j];
			for (auto it : all[i]) ans[it.p] += sum[it.r] - sum[it.l];
		}
	}

	dfs0(rt);

	REP(i, 0, qn) printf("%I64d\n", ans[i]);

	return 0;
}