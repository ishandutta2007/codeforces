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
 
#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() rand()
#endif
 
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef long long LL;
 
const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getchar(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getchar();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

const int maxn = 15000, maxm = 1000, maxq = 35000, max0 = 16;
const int p = 1e7 + 19, q = 1e9 + 7;

int n, K;

int opr[maxq + 5];

int v[maxn + 5], w[maxn + 5];

int ans[max0 + 1][maxm + 5];

int del[maxn + 5];

bool in[maxn + 5];

inline void add(int *ans, int x)
{
	for (int i = K - w[x]; i >= 0; --i) chkmax(ans[i + w[x]], ans[i] + v[x]);
}

inline void work(int l, int r, int dep)
{
	bool flag = 0;
	REP(i, l, r)
		if (opr[i] == -1)
		{
			flag = 1;
			break;
		}
	if (!flag) 
	{
		REP(i, l, r) if (!(opr[i] & 1)) in[opr[i] >> 1] = 1;
		return;
	}
	if (r - l <= 1) 
	{
		LL ret = 0, t = 1;
		REP(i, 1, K + 1)
		{
			(ret += t * ans[dep][i]) %= q;
			(t *= p) %= q;
		}
		printf("%I64d\n", ret);
		return;
	}
	memcpy(ans[dep + 1], ans[dep], sizeof ans[dep + 1]);
	int mid = (l + r) >> 1;
	REP(i, mid, r)
	{
		if (opr[i] >= 0)
		{
			if ((opr[i] & 1) && in[opr[i] >> 1]) add(ans[dep + 1], opr[i] >> 1);
		}
	}
	work(l, mid, dep + 1);
	memcpy(ans[dep + 1], ans[dep], sizeof ans[dep + 1]);
	REP(i, l, mid)
	{
		if (opr[i] >= 0)
		{
			if (!(opr[i] & 1) && del[opr[i] >> 1] >= r) add(ans[dep + 1], opr[i] >> 1);
		}
	}
	work(mid, r, dep + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	scanf("%d%d", &n, &K);
	int qn;
	memset(del, oo, sizeof del);
	REP(i, 0, n) scanf("%d%d", v + i, w + i), opr[i] = i << 1;
	scanf("%d", &qn);
	int tmp = qn + n;
	REP(i, n, qn + n)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%d", v + n, w + n);
			opr[i] = n << 1;
			++n;
		}
		else if (ty == 2)
		{
			scanf("%d", opr + i), --opr[i];
			del[opr[i]] = i;
			(opr[i] <<= 1) |= 1;
		}
		else opr[i] = -1;
	}
	qn = tmp;
	work(0, qn, 0);
	return 0;
}