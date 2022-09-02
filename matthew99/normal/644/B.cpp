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

const int maxn = 200000;

int n, b;

int t[maxn + 5], d[maxn + 5];
LL ans[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &b);
	REP(i, 0, n) scanf("%d%d", t + i, d + i);
	memset(ans, -1, sizeof ans);
	static int q[maxn + 5];
	int head = 0, rear = 0;
	LL T = 0;
	REP(i, 0, n)
	{
		while (head != rear && T <= t[i])
		{
			ans[q[head]] = T += d[q[head]];
			++head;
		}
		chkmax(T, (LL)t[i]);
		if (rear - head != b) q[rear++] = i;
	}
	while (head != rear)
	{
		ans[q[head]] = T += d[q[head]];
		++head;
	}
	REP(i, 0, n) printf("%I64d ", ans[i]);
	return 0;
}