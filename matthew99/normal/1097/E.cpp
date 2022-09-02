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
bool vis[maxn + 5];

vector<vector<int> > ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int _T;
	scanf("%d", &_T);
	while (_T--)
	{
		ans.clear();
		scanf("%d", &n);
		REP(i, 0, n) scanf("%d", a + i);

		int goal = 1;
		while ((goal * (goal + 1) >> 1) < n) ++goal;

		memset(vis, 0, sizeof vis);
		
		while (goal > 0)
		{
			static int fen[maxn + 5];
			static int pre[maxn + 5];
			static int dp[maxn + 5];
			int Max = -1;
			memset(fen, -1, sizeof fen);
			REP(i, 0, n) if (!vis[i])
			{
				int best = -1;
				for (int j = a[i]; j > 0; j -= j & -j)
					if (~fen[j])
					{
						if (!~best || dp[fen[j]] > dp[best]) best = fen[j];
					}
				pre[i] = best;
				if (~best) dp[i] = dp[best] + 1;
				else dp[i] = 1;

				if (!~Max || dp[i] > dp[Max]) Max = i;

				for (int j = a[i]; j <= n; j += j & -j)
					if (!~fen[j] || dp[fen[j]] < dp[i]) fen[j] = i;
			}
			if (dp[Max] < goal)
			{
				while (goal > 0)
				{
					vector<int> seq;
					int lst = -1;
					for (int i = n - 1; i >= 0; --i)
						if (!vis[i] && chkmax(lst, a[i])) seq.pb(i), vis[i] = 1;
					reverse(ALL(seq));
					if (!seq.empty()) ans.pb(seq);
					--goal;
				}
			}
			else
			{
				vector<int> seq;
				for (int i = Max; ~i; i = pre[i]) seq.pb(i), vis[i] = 1;
				reverse(ALL(seq));
				if (!seq.empty()) ans.pb(seq);
				--goal;
			}
		}
		printf("%d\n", SZ(ans));
		for (auto u : ans)
		{
			printf("%d ", SZ(u));
			for (auto v : u) printf("%d ", a[v]);
			printf("\n");
		}
		--goal;
		REP(i, 0, n) assert(vis[i]);
	}
	return 0;
}