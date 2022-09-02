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

const int maxn = 120100, max0 = 17, bs = 50, bc = 2500, maxm = 120100;

int n;
int a[maxn + 5];

int Min[max0][maxn + 5];
int Max[max0][maxn + 5];
int Log[maxn + 5];

inline int get_min(int l, int r)
{
	int tmp = Log[r - l];
	return min(Min[tmp][l], Min[tmp][r - (1 << tmp)]);
}

inline int get_max(int l, int r)
{
	int tmp = Log[r - l];
	return max(Max[tmp][l], Max[tmp][r - (1 << tmp)]);
}

inline bool chk(int l, int r)
{
	return get_max(l, r) - get_min(l, r) + 1 == r - l;
}

vector<pair<int, int> > alll[maxn + 5], allr[maxn + 5]; 

LL ans[maxm + 5];

int bmin[bc + 5], bcnt[bc + 5];
LL tot[bc + 5];

int lst_redo[bc + 5];

inline void redo(int id, int lim, bool ty)
{
	if (lst_redo[id] == lim) return;
	lst_redo[id] = lim;
	bmin[id] = oo, bcnt[id] = 0;
	REP(i, id * bs, (id + 1) * bs)
	{
		if (i < 0 || i > n) continue;
		if (ty == 0 && i >= lim) continue;
		if (ty == 1 && i <= lim) continue;
		int tmp = -1;
		if (ty == 0) tmp = get_max(i, lim) - get_min(i, lim) + i;
		else 
		{
			tmp = get_max(lim, i) - get_min(lim, i) - (i - 1);
		}
		if (chkmin(bmin[id], tmp)) bcnt[id] = 1;
		else if (tmp == bmin[id]) ++bcnt[id];
	}
}

inline void add(int l, int r, int delta, int lim, bool ty)
{
	int whl = l / bs, whr = r / bs;
	if (whl == whr)
	{
		redo(whl, lim, ty);
	}
	else
	{
		redo(whl, lim, ty);
		REP(i, whl + 1, whr) bmin[i] += delta;
		redo(whr, lim, ty);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	REP(i, 0, n) Min[0][i] = a[i], Max[0][i] = a[i];
	REP(i, 1, maxn + 1)
	{
		int u = i;
		Log[i] = -1;
		while (u) u >>= 1, ++Log[i];
	}

	REP(i, 1, max0) REP(j, 0, n)
		if (j + (1 << (i - 1)) >= n) Min[i][j] = Min[i - 1][j], Max[i][j] = Max[i - 1][j];
		else
		{
			Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
			Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
		}

	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		int whl = (l + bs - 1) / bs, whr = r / bs;
		if (whl > whr)
		{
			REP(u, l, r) REP(v, u + 1, r + 1)
				if (chk(u, v)) ++ans[i];
		}
		else
		{
			REP(u, l, whl * bs) REP(v, whr * bs, r + 1)
				if (chk(u, v)) ++ans[i];
			allr[l].pb(mp(whr - 1, i));
			alll[r].pb(mp(whl, i));
		}
	}

	{
		memset(lst_redo, -1, sizeof lst_redo);
		memset(bmin, oo, sizeof bmin);
		memset(bcnt, 0, sizeof bcnt);
		memset(tot, 0, sizeof tot);

		stack<pair<int, int> > stk_min;
		stack<pair<int, int> > stk_max;

		stk_min.push(mp(-1, -1));
		stk_max.push(mp(n, -1));

		REP(i, 0, n)
		{
			{
				int lst = i;
				while (stk_min.top().x > a[i]) 
				{
					int delta = stk_min.top().x - a[i];
					stk_min.pop();
					add(stk_min.top().y + 1, lst, delta, i + 1, 0);
					lst = stk_min.top().y + 1;
				}
				stk_min.push(mp(a[i], i));
			}

			{
				int lst = i;
				while (stk_max.top().x < a[i]) 
				{
					int delta = a[i] - stk_max.top().x;
					stk_max.pop();
					add(stk_max.top().y + 1, lst, delta, i + 1, 0);
					lst = stk_max.top().y + 1;
				}
				stk_max.push(mp(a[i], i));
			}

			add(i, i + 1, i, i + 1, 0);
			REP(j, 0, i / bs + 1)
			{
				if (bmin[j] - i == 0) tot[j] += bcnt[j];
			}

			for (auto j : alll[i + 1])
				REP(k, j.x, i / bs + 1) ans[j.y] += tot[k];
		}
	}

	{
		memset(lst_redo, -1, sizeof lst_redo);
		memset(bmin, oo, sizeof bmin);
		memset(bcnt, 0, sizeof bcnt);
		memset(tot, 0, sizeof tot);

		stack<pair<int, int> > stk_min;
		stack<pair<int, int> > stk_max;

		stk_min.push(mp(-1, n + 1));
		stk_max.push(mp(n, n + 1));

		for (int i = n - 1; i >= 0; --i)
		{
			{
				int lst = i + 2;
				while (stk_min.top().x > a[i]) 
				{
					int delta = stk_min.top().x - a[i];
					stk_min.pop();
					add(lst, stk_min.top().y, delta, i, 1);
					lst = stk_min.top().y;
				}
				stk_min.push(mp(a[i], i));
			}

			{
				int lst = i + 2;
				while (stk_max.top().x < a[i]) 
				{
					int delta = a[i] - stk_max.top().x;
					stk_max.pop();
					add(lst, stk_max.top().y, delta, i, 1);
					lst = stk_max.top().y;
				}
				stk_max.push(mp(a[i], i));
			}

			add(i + 1, i + 2, -i, i, 1);
			REP(j, i / bs, n / bs + 1)
			{
				if (bmin[j] + i == 0) 
				{
					tot[j] += bcnt[j];
				}
			}

			if (!(i % bs)) memset(tot, 0, sizeof tot);

			for (auto j : allr[i])
				REP(k, i / bs, j.x + 1) ans[j.y] += tot[k];
		}
	}

	REP(i, 0, qn) printf("%lld\n", ans[i]);
	return 0;
}