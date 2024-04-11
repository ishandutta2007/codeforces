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

const int maxn = 300100;

struct data
{
	int val, Minp;

	data(): val(0), Minp(0) { }
	data(int _val, int _Minp): val(_val), Minp(_Minp) { }

	friend bool operator<(const data &x, const data &y)
	{
		if (x.val == y.val) return x.Minp > y.Minp;
		return x.val < y.val;
	}

};

data dpu[maxn + 5];
data dpd[maxn + 5];

int n;
int up[maxn + 5], down[maxn + 5], both[maxn + 5];
int jumpu[maxn + 5], jumpd[maxn + 5], jumpb[maxn + 5];

inline void get_jump(int *a, int *jump)
{
	map<LL, int> leftmost;
	leftmost[0] = n;
	LL suf_sum = 0;
	jump[n] = n + 1;
	for (int i = n - 1; i >= 0; --i)
	{
		suf_sum += a[i];
		jump[i] = jump[i + 1];
		if (leftmost.count(suf_sum)) chkmin(jump[i], leftmost[suf_sum]);
		leftmost[suf_sum] = i;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", up + i);
	REP(i, 0, n) scanf("%d", down + i);
	REP(i, 0, n) both[i] = up[i] + down[i];
	get_jump(up, jumpu);
	get_jump(down, jumpd);
	get_jump(both, jumpb);
	REP(i, 0, n + 1)
	{
		chkmax(dpd[jumpd[dpu[i].Minp]], data(dpu[i].val + 1, i));
		chkmax(dpu[jumpu[dpd[i].Minp]], data(dpd[i].val + 1, i));
		chkmax(dpu[jumpu[i]], data(dpu[i].val + 1, dpu[i].Minp));
		chkmax(dpd[jumpd[i]], data(dpd[i].val + 1, dpd[i].Minp));

		chkmax(dpu[i + 1], dpu[i]);
		chkmax(dpd[i + 1], dpd[i]);

		data tmp = data(max(dpu[i].val, dpd[i].val) + 1, jumpb[i]);
		chkmax(dpd[jumpb[i]], tmp);
	}
	printf("%d\n", max(dpu[n].val, dpd[n].val));
	return 0;
}