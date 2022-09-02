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

int d[maxn + 5];
int fa[maxn + 5];

inline LL construct(int lim)
{
	LL ret = 1;
	int cur = 0, deg = 0;
	d[0] = 1;
	REP(i, 1, n)
	{
		fa[i] = cur;
		d[i] = d[cur] + 1;
		ret += d[i];
		++deg;
		if (deg == lim) ++cur, deg = 0;
	}
	return ret;
}

bool in[maxn + 5];
int place[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	LL s;
	cin >> n >> s;
	LL Max = (LL)n * (n + 1) >> 1;
	if (s > Max || s < 1 + 2 * (n - 1)) puts("No");
	else if (s == Max)
	{
		puts("Yes");
		REP(i, 1, n) printf("%d ", i);
		printf("\n");
	}
	else
	{
		int l = 2, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (construct(mid) > s) l = mid + 1;
			else r = mid;
		}
		LL curs = construct(l);
		fa[0] = -1;
		memset(place, -1, sizeof place);
		memset(in, 0, sizeof in);
		int u = n - 1;
		while (~u) place[d[u]] = u, in[u] = 1, u = fa[u];

		int lst = n - 1;
		for (int i = n - 2; curs < s; --i)
		{
			if (!in[i])
			{
				curs -= d[i];
				if (curs + d[lst] + 1 > s)
					fa[i] = place[s - curs - 1];
				else
					fa[i] = lst;
				lst = i;
				d[i] = d[fa[i]] + 1;
				curs += d[i];
				place[d[i]] = i;
			}
		}
		puts("Yes");
		REP(i, 1, n) printf("%d ", fa[i] + 1);
		printf("\n");
	}
	return 0;
}