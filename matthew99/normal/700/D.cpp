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

const int maxn = 100100, maxm = 100100, maxa = 100100;

const int sqrtn = 320;

int bel[maxn + 5];

struct data
{
	int id, x, y;

	data() { }
	data(int _id, int _x, int _y): id(_id), x(_x), y(_y) { }

	friend bool operator<(const data &x, const data &y)
	{
		if (bel[x.x] == bel[y.x])
		{
			if (bel[x.x] & 1) return x.y < y.y;
			return x.y > y.y;
		}
		return x.x < y.x;
	}

};

int n, m;
int a[maxn + 5];

data q[maxm + 5];

int ans[maxm + 5];

int fq[maxn + 5];
int cnt[maxa + 5];
int num[maxn + 5];
vector<int> big;

inline void change_cnt(int x, int y)
{
	cnt[x] += y;
}

inline void add(int x, int y)
{
	--num[fq[a[x]]];
	fq[a[x]] += y;
	++num[fq[a[x]]];
}

inline int calc()
{
	priority_queue<int, vector<int>, greater<int> > all;
	int ret = 0;
	static int tmp[sqrtn + 5];
	memcpy(tmp, num, sizeof(tmp));
	int lst = 0;
	REP(i, 1, sqrtn) if (tmp[i])
	{
		if (lst)
		{
			ret += lst + i;
			--tmp[i];
			if (lst + i >= sqrtn) all.push(lst + i);
			else ++tmp[lst + i];
			lst = 0;
		}
		ret += i * (tmp[i] & ~1);
		if ((i << 1) < sqrtn) tmp[i << 1] += tmp[i] >> 1;
		else REP(j, 0, tmp[i] >> 1) all.push(i << 1);
		if (tmp[i] & 1) lst = i;
	}
	for (auto u : big) if (fq[u] >= sqrtn) all.push(fq[u]);
	while (!all.empty())
	{
		int x = all.top(); all.pop();
		if (lst) 
		{
			ret += lst + x;
			all.push(lst + x);
			lst = 0;
		}
		else lst = x;
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, maxn + 1) bel[i] = i / sqrtn;
	scanf("%d", &n);
	big.clear();
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		if ((++cnt[a[i]]) == sqrtn) big.pb(a[i]);
	}
	scanf("%d", &m);
	REP(i, 0, m)
	{
		scanf("%d%d", &q[i].x, &q[i].y), --q[i].x;
		q[i].id = i;
	}
	sort(q, q + m);
	int l = 0, r = 0;
	REP(i, 0, m)
	{
		while (l > q[i].x) add(--l, 1);
		while (r < q[i].y) add(r++, 1);
		while (l < q[i].x) add(l++, -1);
		while (r > q[i].y) add(--r, -1);
		ans[q[i].id] = calc();
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}