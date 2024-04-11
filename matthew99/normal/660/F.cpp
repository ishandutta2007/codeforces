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

const int Mod = 1e9 + 7;

const int maxn = 200100;

int n;

LL sum0[maxn + 5], sum1[maxn + 5];

//sum0[j] - sum0[i] - i * (sum1[j] - sum1[i])
//sum0[j] - i * sum1[j] - sum0[i] + i * sum1[i]

inline bool check(const pair<int, LL> &x, const pair<int, LL> &y, const pair<int, LL> &z)
{
	return (y.x - x.x) * (z.y - x.y) - (y.y - x.y) * (z.x - x.x) > 0;
}

inline LL calc(const pair<int, LL> &x, const LL &y) { return x.x * y + x.y; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	sum0[0] = sum1[0] = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		sum0[i + 1] = sum0[i] + (LL)(i + 1) * x;
		sum1[i + 1] = sum1[i] + x;
	}
	static pair<int, LL> stk[maxn + 5];
	int top = 0;
	stk[top++] = mp(0, sum0[0]);
	LL ans = 0;
	REP(i, 1, n + 1)
	{
		auto tmp = mp(-i, -sum0[i] + i * sum1[i]);
		while (top > 1 && !check(stk[top - 2], stk[top - 1], tmp)) --top; stk[top++] = tmp;
		int l = 0, r = top - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (calc(stk[mid], sum1[i]) < calc(stk[mid + 1], sum1[i])) l = mid + 1;
			else r = mid;
		}
		chkmax(ans, calc(stk[l], sum1[i]) + sum0[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}