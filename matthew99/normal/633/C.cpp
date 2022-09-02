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

const int maxn = 10000, max0 = 1000000, max1 = 1000;

const int maxm = 100000;

struct node
{
	int id, dep;
	int p;
	node *go[26];
	node *f;
 
	node(): id(-1), dep(-1), f(NULL) { memset(go, 0, sizeof go); }
};
 
node nd[max0 + 5];
int cur = 0;
 
node *rt;

string str[maxm + 5];
 
node *add(node *&rt, char *s)
{
	node **tmp = &rt;
	for (int i = 0; ; ++i)
	{
		node *&a = *tmp;
		if (!a) a = nd + (cur++), a->p = i ? s[i - 1] - 'a' : 0;
		a->dep = i;
		if (s[i]) tmp = &a->go[s[i] - 'a'];
		else break;
	}
	return *tmp;
}

int n, m;
char s[maxn + 5];

bool ty[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	REP(i, 0, n) ty[i] = isupper(s[i]), s[i] = tolower(s[i]);
	reverse(s, s + n);
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static char s0[maxn + 5];
		scanf("%s", s0);
		int m = strlen(s0);
		str[i] = s0;
		REP(j, 0, m) s0[j] = tolower(s0[j]);
		node *tmp = add(rt, s0);
		tmp->id = i;
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
	static pair<int, int> pre[maxn + 5];
	REP(i, 0, n + 1) pre[i].x = -1;
	pre[0].x = 0;
	REP(i, 0, n)
		if (pre[i].x != -1)
		{
			node *now = rt;
			REP(j, i, min(n, i + max1))
			{
				if (now->go[(int)(s[j] - 'a')]->dep != now->dep + 1) break;
				now = now->go[(int)(s[j] - 'a')];
				if (now->id != -1) pre[j + 1] = mp(i, now->id);
			}
		}
	int u = n;
	while (u)
	{
		cout << str[pre[u].y] << ' ';
		u = pre[u].x;
	}
	return 0;
}