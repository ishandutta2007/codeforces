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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 300000;

int n, qn;
vector<int> all[maxn + 5];

int num = 0;

int lst;
bool vis[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	int cnt = 0;
	REP(i, 0, qn)
	{
		int ty, x;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d", &x), --x;
			all[x].pb(cnt++);
			++num;
		}
		else if (ty == 2)
		{
			scanf("%d", &x), --x;
			for (auto u : all[x])
			{
				if (!vis[u])
				{
					vis[u] = 1;
					--num;
				}
			}
			all[x].clear();
		}
		else if (ty == 3)
		{
			scanf("%d", &x);
			REP(j, lst, x)
				if (!vis[j]) vis[j] = 1, --num;
			chkmax(lst, x);
		}
		printf("%d\n", num);
	}
	return 0;
}