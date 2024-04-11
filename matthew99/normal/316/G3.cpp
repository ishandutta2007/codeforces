#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxlen = 50000, maxn = 10;

char s[maxlen + 5];
int n;

struct node
{
	node *p;
	map<int, node*> go;
	unsigned short cnt[maxn + 5];
	int val;
	int deg;
	
	node(const int &_val = 0): p(NULL), val(_val), deg(0) { memset(cnt, 0, sizeof cnt); }
};

node all[((maxlen * (maxn + 1) + maxn) << 1) + 5];
int tot = 0;

node *rt = NULL, *lst = NULL;

node *new_node(const int &_val = 0)
{
	all[tot] = node(_val);
	return all + (tot++);
}

void init_sam()
{
	tot = 0;
	lst = rt = new_node();
}

void extend(const int &w, const int &ty = -1)
{
	node *p = lst, *np = new_node(p->val + 1);
	if (ty >= 0) np->cnt[ty] = 1;
	while (p && !p->go[w]) p->go[w] = np, p = p->p;
	if (!p) np->p = rt;
	else
	{
		node *q = p->go[w];
		if (q->val == p->val + 1) np->p = q;
		else
		{
			node *nq = new_node(p->val + 1);
			nq->go = q->go;
			nq->p = q->p, np->p = q->p = nq;
			while (p && p->go[w] == q) p->go[w] = nq, p = p->p;
		}
	}
	lst = np;
}

int L[maxn + 5], R[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init_sam();
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 0; s[i]; ++i) extend(s[i] - 'a', n);
	REP(i, 0, n)
	{
		extend(26);
		scanf("%s%d%d", s, L + i, R + i);
		for (int j = 0; s[j]; ++j) extend(s[j] - 'a', i);
	}
	int ans = 0;
	queue<node*> q;
	REP(i, 1, tot) ++(all + i)->p->deg;
	REP(i, 0, tot)
		if (!(all + i)->deg) q.push(all + i);
	while (!q.empty())
	{
		node *u = q.front(); q.pop();
		if (!u->p) continue;
		REP(i, 0, n + 1) u->p->cnt[i] += u->cnt[i];
		if (!--u->p->deg) q.push(u->p);
	}
	for (int i = tot - 1; i >= 1; --i) 
	{
		node *u = all + i;
		int len = u->val - u->p->val;
		if (!u->cnt[n]) continue;
		REP(j, 0, n) if (u->cnt[j] < L[j] || u->cnt[j] > R[j]) goto yyt;
		ans += len;
yyt:;
	}
	printf("%d\n", ans);
	return 0;
}