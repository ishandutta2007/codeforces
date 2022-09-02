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

const int maxn = 100000, maxm = 100000, max0 = 320, max1 = 320;

int n, m, qn;
LL a[maxn + 5];

vector<int> S[maxm + 5];

int id[maxm + 5];
int tot = 0;
LL ans[max1 + 5];

int cnt[maxn + 5][max1 + 5];

LL add[max1 + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, n) scanf("%I64d", a + i);
	REP(i, 0, m)
	{
		id[i] = -1;
		int k;
		scanf("%d", &k);
		if (k >= max0) id[i] = tot++;
		S[i].resize(k);
		REP(j, 0, k) scanf("%d", &S[i][j]), --S[i][j];
	}
	REP(i, 0, m)
		if (id[i] >= 0)
		{
			static bool vis[maxn + 5];
			memset(vis, 0, sizeof vis);
			ans[id[i]] = 0;
			for (auto x : S[i]) vis[x] = 1, ans[id[i]] += a[x];
			REP(j, 0, m)
			{
				cnt[j][id[i]] = 0;
				for (auto x : S[j]) cnt[j][id[i]] += vis[x];
			}
		}
	REP(i, 0, qn)
	{
		char s[3];
		scanf("%s", s);
		if (s[0] == '?')
		{
			int x;
			scanf("%d", &x), --x;
			LL ret = 0;
			if (id[x] != -1) ret = ans[id[x]];
			else
			{
				REP(i, 0, tot) ret += add[i] * cnt[x][i];
				for (auto i : S[x]) ret += a[i];
			}
			printf("%I64d\n", ret);
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y), --x;
			REP(i, 0, tot) ans[i] += (LL)y * cnt[x][i];
			if (id[x] == -1) for (auto i : S[x]) a[i] += y;
			else add[id[x]] += y;
		}
	}
	return 0;
}