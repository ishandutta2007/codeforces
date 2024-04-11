#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).End()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000100;

int n;
char a_input[maxn + 5], b_input[maxn + 5];
char a[maxn + 5], b[maxn + 5];

int len[maxn + 5];

pair<int, int> f[maxn + 5];
map<int, pair<int, int> > g[maxn + 5];

int nxt[maxn + 5];

int get_nxt(int x)
{
	if (nxt[x] == x) return x;
	return nxt[x] = get_nxt(nxt[x]);
}

vector<int> End[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", a_input);
	scanf("%s", b_input);
	n = strlen(a_input);
	REP(i, 0, n)
	{
		a[i << 1] = a_input[i];
		a[i << 1 | 1] = '*';
		b[i << 1] = b_input[i];
		b[i << 1 | 1] = '*';
	}
	n <<= 1;

	int Max = -1;
	REP(i, 0, n)
	{
		if (a[i] != b[i]) len[i] = -1;
		else
		{
			int j = 0;
			if (~Max && Max + len[Max] > i) j = min(Max + len[Max] - i, len[(Max << 1) - i]);
			while (i - j - 1 >= 0 && i + j + 1 < n && a[i - j - 1] == b[i + j + 1] && b[i - j - 1] == a[i + j + 1]) ++j;
			len[i] = j;
			if (!~Max || i + len[i] > Max + len[Max]) Max = i;
		}
	}

	REP(i, 0, n) End[i + len[i] + 1].pb(i);

	REP(i, 0, n + 1) f[i] = mp(oo, -1);

	f[0] = mp(0, -1);
	REP(i, 0, n + 1) nxt[i] = i;
	REP(i, 0, n) 
	{
		for (auto u : End[i])
			nxt[u] = get_nxt(u + 1);
		if (a[i] == b[i]) chkmin(f[i + 1], mp(f[i].x, i));
		int tmp = ((get_nxt(0)) << 1) - i;
		if (tmp <= i)
		{
			chkmin(f[i + 1], mp(f[tmp].x + 1, tmp));
			int nxt = ((get_nxt(((i + tmp) >> 1) + 1) << 1) - i);
			while (nxt <= i)
			{
				int len = nxt - tmp;
				if (!g[i + 1].count(len)) g[i + 1][len] = mp(oo, -1);
				if ((len << 1) <= i + 1 - tmp)
				{
					if ((i + 1 - tmp) % len)
					{
						int lst = i + 1 - (i + 1 - tmp) % len;
						chkmin(g[i + 1][len], mp(f[lst].x + 1, lst));
					}
					else
					{
						chkmin(g[i + 1][len], mp(f[i + 1 - len].x + 1, i + 1 - len));
					}
					if (g[i + 1 - len].count(len)) 
					{
						chkmin(g[i + 1][len], g[i + 1 - len][len]);
					}
					nxt = i + 1 - len - (i + 1 - tmp) % len;
				}
				else 
				{
					chkmin(g[i + 1][len], mp(f[nxt].x + 1, nxt));
				}
				chkmin(f[i + 1], g[i + 1][len]);
				tmp = nxt;
				nxt = ((get_nxt(((i + tmp) >> 1) + 1) << 1) - i);
			}
		}
	}
	if (f[n].x >= oo) printf("-1\n");
	else
	{
		printf("%d\n", f[n].x);
		int tmp = n;
		while (tmp >= 0)
		{
			if (f[tmp].y < tmp - 1) printf("%d %d\n", ((f[tmp].y + 1) >> 1) + 1, ((tmp - 1) >> 1) + 1);
			tmp = f[tmp].y;
		}
	}
	return 0;
}