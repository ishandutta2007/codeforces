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

const int max0 = 30;

const int maxn = 300100;

int n;
int a[maxn + 5], p[maxn + 5];
 
struct node
{
	node *c[2];

	int sum;

};

const int max1 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max1], nd_res = max1;
	return nd_pool + (--nd_res);
}

node *rt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n) 
	{
		node *cur;
		if (!rt) rt = newnode();
		cur = rt;
		++cur->sum;
		for (int j = max0 - 1; j >= 0; --j)
		{
			int x = p[i] >> j & 1;
			if (!cur->c[x]) cur->c[x] = newnode();
			cur = cur->c[x];
			++cur->sum;
		}
	}
	REP(i, 0, n)
	{
		node *cur = rt;
		--cur->sum;
		int ret = 0;
		for (int j = max0 - 1; j >= 0; --j)
		{
			int x = a[i] >> j & 1;
			if (cur->c[x] && cur->c[x]->sum) cur = cur->c[x];
			else cur = cur->c[!x], ret |= 1 << j;
			--cur->sum;
		}
		printf("%d ", ret);
	}
	return 0;
}