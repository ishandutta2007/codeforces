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

const int maxn = 1000000;

int fa[maxn + 5];

int get(const int &x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int a[maxn + 5];

vector<pair<int, int> > all;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	REP(i, 0, n + 1) fa[i] = i;
	memset(a, -1, sizeof a);
	int lst = -1;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		if (x == i) lst = i, ++cnt;
	}
	if (cnt > 0)
	{
		printf("YES\n");
		REP(i, 1, n + 1)
			if (i != lst) printf("%d %d\n", lst, i);
		return 0;
	}
	int x = -1, y = -1;
	REP(i, 1, n + 1) 
	{
		if (a[i] != i && a[a[i]] == i) x = i, y = a[i];
	}
	if (x == -1) printf("NO\n");
	else
	{
		vector<pair<int, int> > ans;
		static bool vis[maxn + 5] = {0};
		ans.pb(mp(x, y));
		REP(i, 1, n + 1)
		{
			if (i != x && i != y && !vis[i])
			{
				int u = i;
				int cnt = 0;
				do
				{
					ans.pb(mp(u, x));
					swap(x, y);
					++cnt;
					vis[u] = 1;
					u = a[u];
				}
				while (u != i);
				if (cnt & 1)
				{
					printf("NO\n");
					exit(0);
				}
			}
		}
		printf("YES\n");
		for (auto it : ans) printf("%d %d\n", it.x, it.y);
	}
	return 0;
}