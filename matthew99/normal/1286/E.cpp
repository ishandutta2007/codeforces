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

const int maxn = 600100;

int qn;
int a[maxn + 5];

int w[maxn + 5];

struct Data
{
	int start, period, len;

	LL sum;

	Data() { }
	Data(int _start, int _period, int _len, const LL &_sum): start(_start), period(_period), len(_len), sum(_sum) { }

};

int n;

inline bool check(int x) { return a[n - 1] == a[n - x - 1]; }

vector<pair<int, int> > allw;

inline int eval(int x)
{
	return allw[lower_bound(ALL(allw), mp(x, -1)) - allw.begin()].y;
}

vector<Data> all;

inline void add(int x, int y)
{
	for (auto &u : all)
	{
		if (u.start >= x) u.sum += (LL)y * u.len;
		else if (u.start + (u.len - 1) * u.period >= x)
		{
			//u.start + k * u.period >= x
			//k * u.period >= x - u.start
			//k >= (x - u.start + u.period - 1) / u.period
			u.sum += (LL)y * (u.len - (x - u.start + u.period - 1) / u.period);
		}
	}
}

inline void append(vector<Data> &v, const Data &x)
{
	if (!v.empty())
	{
		if (!v[SZ(v) - 1].period)
		{
			if (!x.period)
			{
				v[SZ(v) - 1].period = x.start - v[SZ(v) - 1].start;
				v[SZ(v) - 1].len += x.len;
				v[SZ(v) - 1].sum += x.sum;
			}
			else if (x.start - v[SZ(v) - 1].start == x.period)
			{
				v[SZ(v) - 1].period = x.period;
				v[SZ(v) - 1].len += x.len;
				v[SZ(v) - 1].sum += x.sum;
			}
			else v.pb(x);
		}
		else if (v[SZ(v) - 1].start + v[SZ(v) - 1].len * v[SZ(v) - 1].period == x.start && (!x.period || x.period == v[SZ(v) - 1].period))
		{
			v[SZ(v) - 1].len += x.len;
			v[SZ(v) - 1].sum += x.sum;
		}
		else v.pb(x);
	}
	else v.pb(x);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	unsigned long long ans = 0;
	int ans26 = 0;
	scanf("%d", &qn);
	allw.pb(mp(-1, -1));
	REP(_i, 0, qn)
	{
		char c[2];
		int ww;
		scanf("%s%d", c, &ww);
		int cc = c[0] - 'a';
		cc = (cc + ans26) % 26;
		(ww ^= ans & ((1 << 30) - 1));
		a[_i] = cc;
		w[_i] = ww;
		n = _i + 1;
		while (!allw.empty())
		{
			if (allw[SZ(allw) - 1].y > ww)
			{
				add(allw[SZ(allw) - 2].x + 1, allw[SZ(allw) - 2].y - allw[SZ(allw) - 1].y);
				allw.pop_back();
			}
			else break;
		}
		add(allw[SZ(allw) - 1].x + 1, ww - allw[SZ(allw) - 1].y);
		allw.pb(mp(n - 1, ww));

		vector<Data> new_all;
		for (auto u : all)
		{
			if (!check(u.start + u.period * (u.len - 1)))
			{
				if (check(u.start)) append(new_all, Data(u.start, 0, 1, eval(u.start)));
			}
			else if (!check(u.start))
			{
				if (u.len == 2)
				{
					append(new_all, Data(u.start + u.period, 0, 1, eval(u.start + u.period)));
				}
				else if (u.len > 2)
				{
					append(new_all, Data(u.start + u.period, u.period, u.len - 1, u.sum - eval(u.start)));
				}
			}
			else append(new_all, u);
		}
		if (a[n - 1] == a[0])
		{
			append(new_all, Data(n - 1, 0, 1, ww));
		}
		all = new_all;

		for (auto u : all) ans += u.sum, ans26 = (ans26 + u.sum) % 26;
		printf("%llu\n", ans);
	}
	return 0;
}