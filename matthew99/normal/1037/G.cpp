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

const int maxn = 100100;

int n;
int a[maxn + 5];

int pre[maxn + 5][27];
int nxt[maxn + 5][27];

int cnt[27][maxn + 5];
int sg_sum[27][maxn + 5];

int sg_pre[maxn + 5][27];
int sg_suf[maxn + 5][27];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	{
		static char s[maxn + 5];
		scanf("%s", s);
		n = strlen(s);
		REP(i, 0, n) a[i] = s[i] - 'a';
	}
	memset(pre, -1, sizeof pre);
	REP(i, 0, n) 
	{
		REP(j, 0, 26) pre[i + 1][j] = pre[i][j];
		pre[i + 1][a[i]] = i;
	}

	REP(i, 0, 26) nxt[n][i] = n;
	for (int i = n - 1; i >= 0; --i)
	{
		REP(j, 0, 26) nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i]] = i;
	}

	static int lst[27];
	memset(lst, -1, sizeof lst);
	REP(i, 0, n)
	{
		REP(j, 0, 26) 
		{
			sg_sum[j][i + 1] ^= sg_sum[j][i];
			cnt[j][i + 1] += cnt[j][i];
		}
		++cnt[a[i]][i + 1];

		lst[a[i]] = i;

		int pos[27];
		REP(j, 0, 26) pos[j] = j;
		sort(pos, pos + 26, [&](int x, int y) { return lst[x] > lst[y]; });

		REP(_j, 0, 26)
		{
			int j = pos[_j];
			if (lst[j] == i) sg_pre[i + 1][j] = 0;
			else
			{
				int from = lst[j] + 1, to = i + 1;
				bool vis[27] = {0};
				REP(k, 0, 26)
				{
					if (cnt[k][to] - cnt[k][from])
					{
						int tmp = sg_pre[i + 1][k];
						tmp ^= sg_sum[k][pre[to][k]] ^ sg_sum[k][nxt[from][k]];
						tmp ^= sg_pre[nxt[from][k]][j];
						vis[tmp] = 1;
					}
				}
				sg_pre[i + 1][j] = 0;
				while (vis[sg_pre[i + 1][j]]) ++sg_pre[i + 1][j];
			}
			if (i + 1 == n || j == a[i + 1]) sg_sum[j][i + 1] ^= sg_pre[i + 1][j];
		}
	}

	REP(i, 0, 26) lst[i] = n;
	for (int i = n - 1; i >= 0; --i)
	{
		lst[a[i]] = i;

		int pos[27];
		REP(j, 0, 26) pos[j] = j;
		sort(pos, pos + 26, [&](int x, int y) { return lst[x] < lst[y]; });

		REP(_j, 0, 26)
		{
			int j = pos[_j];
			if (lst[j] == i) sg_suf[i][j] = 0;
			else
			{
				int from = i, to = lst[j];
				bool vis[27] = {0};
				REP(k, 0, 26)
					if (cnt[k][to] - cnt[k][from])
					{
						int tmp = sg_suf[i][k];
						tmp ^= sg_sum[k][pre[to][k]] ^ sg_sum[k][nxt[from][k]];
						tmp ^= sg_suf[pre[to][k] + 1][j];
						vis[tmp] = 1;
					}
				sg_suf[i][j] = 0;
				while (vis[sg_suf[i][j]]) ++sg_suf[i][j];
			}
		}
	}

	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		bool ret = 0;
		REP(j, 0, 26) if (cnt[j][r] - cnt[j][l])
		{
			int tmp = sg_suf[l][j];
			tmp ^= sg_sum[j][pre[r][j]] ^ sg_sum[j][nxt[l][j]];
			tmp ^= sg_pre[r][j];
			if (!tmp) ret = 1;
		}
		puts(ret ? "Alice" : "Bob");
	}

	return 0;
}