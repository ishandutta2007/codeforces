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

const int maxn = 310;

bool vis[maxn + 5][maxn + 5];
int a[maxn * maxn + 5];
int pos[maxn * maxn + 5];
int b[maxn + 5][maxn + 5];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(vis, 0, sizeof vis);
		REP(i, 0, n * m) scanf("%d", a + i), pos[i] = i;
		sort(pos, pos + n * m, [&] (int x, int y) { return a[x] < a[y]; });
		int u = 0, v = 0;
		for (int i = 0; i < n * m; )
		{
			int j = i;
			vector<int> id;
			for ( ; j < n * m && a[pos[i]] == a[pos[j]]; ++j) id.pb(pos[j]);
			sort(ALL(id));
			int num = SZ(id);
			int k = 0;
			while (k < num)
			{
				if (num - k < m - v)
				{
					for (int l = num - 1; l >= k; --l)
					{
						b[u][v++] = id[l];
					}
					k = num;
				}
				else
				{
					int tmp = m - v;
					for (int l = k + tmp - 1; l >= k; --l)
					{
						b[u][v++] = id[l];
					}
					k += tmp; 
					v = 0;
					++u;
				}
			}
			i = j;
		}
		int ans = 0;
		REP(i, 0, n)
		{
			REP(j, 0, m)
			{
				REP(k, 0, j)
				{
					if (b[i][k] < b[i][j]) ++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}