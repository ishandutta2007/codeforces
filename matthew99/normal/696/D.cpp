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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 210;
const int maxl = 210;

int n;
LL K;

struct node
{
	int val, dep;
	int p;
	node *go[26];
	node *f;
 
	node(): dep(-1), f(NULL) { memset(go, 0, sizeof go); }
};
 
node nd[maxl + 5];
int cur = 0;

int N;
 
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
 
node *rt;

LL f[maxl + 5][maxl + 5];

inline void mul(LL a[maxl + 5][maxl + 5], LL b[maxl + 5][maxl + 5])
{
	static LL ans[maxl + 5][maxl + 5];
	memset(ans, -oo, sizeof ans);
	REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) chkmax(ans[i][k], a[i][j] + b[j][k]);
	REP(i, 0, N) REP(j, 0, N) a[i][j] = ans[i][j];
}

int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> K;
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n)
	{
		static char s[maxl + 5];
		scanf("%s", s);
		node *tmp = add(rt, s);
		tmp->val += a[i];
	}
	static node *q[maxl + 5];
	int head = 0, rear = 0;
	q[rear++] = rt;
	rt->f = rt;
	while (head != rear)
	{
		node *x = q[head++];
		if (x->f != rt) x->val += x->f->val;
		for (int i = 0; i < 26; ++i)
		{
			node *y = x->go[i];
			if (!y) x->go[i] = x == rt ? rt : x->f->go[i];
			else q[rear++] = y, y->f = x == rt ? x : x->f->go[y->p];
		}
	}
	N = cur;
	memset(f, -oo, sizeof f);
	REP(i, 0, N)
		REP(j, 0, 26)
		{
			int y = nd[i].go[j] - nd;
			chkmax(f[i][y], (LL)nd[y].val); 
		}
	static LL now[maxl + 5][maxl + 5];
	memset(now, -oo, sizeof now);
	REP(i, 0, N) now[i][i] = 0;
	for ( ; K; K >>= 1, mul(f, f)) if (K & 1) mul(now, f);
	LL ans = 0;
	REP(i, 0, N) chkmax(ans, now[0][i]);
	cout << ans << endl;
	return 0;
}