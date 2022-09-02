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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n, b[3];
int a[maxn + 5];

bool vis[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d%d%d", b, b + 1, b + 2);
	sort(b, b + 3);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	int cnt0 = 0, cnt1 = 0;
	int ans = 0;
	int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] > b[0] + b[1] + b[2])
		{
			printf("-1\n");
			return 0;
		}
		if (a[i] > b[1] + b[2]) ++ans, vis[i] = 1;
		else if (a[i] > b[0] + b[2]) ++ans, ++cnt0, vis[i] = 1;
		else if (a[i] > b[0] + b[1] && a[i] > b[2]) ++ans, ++cnt1, vis[i] = 1;
		else if (a[i] <= b[0] && cnt0) vis[i] = 1, --cnt0;
		else if (a[i] <= b[1] && cnt1) vis[i] = 1, --cnt1;
		else
		{
			++sum0;
			if (a[i] > b[0]) ++sum1;
			if (a[i] > b[1]) ++sum0;
			if (a[i] > b[0] + b[1]) ++sum3;
		}
	}
	int Min = oo;
	if (!sum3) chkmin(Min, max((sum0 + 1) >> 1, sum1));
	for (int i = n - 1; i >= 0; --i)
		if (!vis[i] && a[i] <= b[2])
		{
			++sum2;
			vis[i] = 1;
			--sum0;
			if (a[i] > b[0]) --sum1;
			if (a[i] > b[1]) --sum0;
			if (a[i] > b[0] + b[1]) --sum3;
			if (!sum3) chkmin(Min, max(sum2, max((sum0 + 1) >> 1, sum1)));
		}
	ans += Min;
	printf("%d\n", ans);
	return 0;
}