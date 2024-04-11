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

const int maxn = 100000;

int n;

int pos[maxn + 5];
int h[maxn + 5];

inline bool cmp(const int &x, const int &y) { return h[x] < h[y]; }

bool vis[maxn + 5];
int q[maxn + 5];
int head = 0, rear = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", h + i), pos[i] = i;
	sort(pos, pos + n, cmp);
	int ret = 0;
	q[rear++] = -1;
	q[rear++] = n;
	int j = 0;
	while (1)
	{
		++ret;
		int tmp = rear;
		REP(i, head, rear)
		{
			const int &x = q[i];
			REP(y, x - 1, x + 2)
				if (y >= 0 && y < n && !vis[y])
				{
					vis[y] = 1;
					q[rear++] = y;
				}
		}
		head = tmp;
		while (j < n && h[pos[j]] <= ret) 
		{
			int x = pos[j];
			REP(y, x, x + 1)
				if (y >= 0 && y < n && !vis[y])
				{
					vis[y] = 1;
					q[rear++] = y;
				}
			++j;
		}
		if (rear == n + 2) break;
	}
	printf("%d\n", ret);
	return 0;
}