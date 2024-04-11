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

const int maxh = 3000, maxw = 3000, maxn = 3000;

int H, W, n, K;

vector<int> all[maxn + 5];

int fa_nxt[maxw + 5], fa_pre[maxw + 5];
inline int get(int x, int *fa) { return fa[x] == x ? x : fa[x] = get(fa[x], fa); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &H, &W, &n, &K);
	REP(i, 0, n) 
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		all[x].pb(y);
	}
	REP(i, 0, H) sort(ALL(all[i]));
	LL ans = 0;
	REP(i, 0, H)
	{
		int sum = 0;
		static int cnt[maxw + 5], p[maxw + 5], need[maxw + 5];
		memset(cnt, 0, sizeof cnt);
		REP(j, i, H) for (auto x : all[j]) ++cnt[x];
		fa_nxt[W] = W;
		fa_pre[0] = 0;
		REP(j, 0, W) if (cnt[j]) fa_nxt[j] = j, fa_pre[j + 1] = j + 1; else fa_nxt[j] = j + 1, fa_pre[j + 1] = j;
		int k = 0, l = 0;
		REP(j, 0, W + 1)
		{
			while (l >= K) { l -= cnt[k++]; }
			sum += k;
			p[j] = k;
			need[j] = K - l;
			l += cnt[j];
		}
		for (int j = H - 1; j >= i; --j)
		{
			ans += sum;
			for (auto x : all[j])
			{
				--cnt[x];
				int u = x;
				while (u != W)
				{
					int nxt = get(u + 1, fa_nxt);
					if (p[nxt] > x + 1) break;
					if (p[nxt])
					{
						if (p[nxt] <= x) ++need[nxt];
						if (need[nxt] > cnt[p[nxt] - 1])
						{
							need[nxt] -= cnt[p[nxt] - 1];
							int nxtp = get(p[nxt] - 1, fa_pre);
							sum += (nxt - u) * (nxtp - p[nxt]);
							p[nxt] = nxtp;
						}
					}
					u = nxt;
				}
				if (!cnt[x])
				{
					fa_nxt[x] = get(x + 1, fa_nxt);
					fa_pre[x + 1] = get(x, fa_pre);
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}