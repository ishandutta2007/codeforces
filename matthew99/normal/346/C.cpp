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

const int max0 = 1000000;

int n;

set<int> allx;

int Max[max0 + 5];

pair<int, int> q[max0 + 5];
int head = 0, rear = 0;

inline void add(int x, int y)
{
	if (q[rear - 1].x >= x) return;
	while (head != rear && q[rear - 1].y == y) --rear;
	q[rear++] = mp(x, y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	allx.clear();
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		if (x > 2) allx.insert(x);
	}
	int a, b;
	scanf("%d%d", &b, &a);
	for (auto x : allx) for (int tmp = (a + x - 1) / x * x; tmp <= b; tmp += x) chkmax(Max[tmp - a], x);
	q[rear++] = mp(0, 0);
	REP(i, 0, b - a)
	{
		int val = q[head].y;
		if (head != rear && q[head].x == i) ++head;
		add(i + 1, val + 1);
		if (Max[i] > 2) add(i + Max[i] - 1, val + 1);
	}
	assert(head != rear);
	printf("%d\n", q[head].y);
	return 0;
}