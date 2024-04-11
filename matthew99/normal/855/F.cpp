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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxq = 50100;

const int maxn = 100100;

const int block = 230;

int qn;

int up[maxn + 5], down[maxn + 5];

struct data
{
	int ty, l, r, K;

	data() { }
	data(int _ty, int _l, int _r, int _K): ty(_ty), l(_l), r(_r), K(_K) { }

};

struct que
{
	int id, p, up, down;

	que() { }
	que(int _id, int _p, int _up, int _down): id(_id), p(_p), up(_up), down(_down) { }


};

inline bool cmp_up(const que &x, const que &y) { return x.up < y.up; }
inline bool cmp_down(const que &x, const que &y) { return x.down < y.down; }

data q[maxq + 5];

LL ans[maxq + 5];

int n = 100010;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(up, oo, sizeof up);
	memset(down, oo, sizeof down);
	scanf("%d", &qn);
	for (int i = 0; i < qn; i += block)
	{
		int to = min(i + block, qn);

		vector<int> all;
		REP(j, i, to)
		{
			scanf("%d%d%d", &q[j].ty, &q[j].l, &q[j].r);
			all.pb(q[j].l);
			all.pb(q[j].r);
			if (q[j].ty == 1) scanf("%d", &q[j].K);
		}
		sort(ALL(all));
		all.resize(unique(ALL(all)) - all.begin());
		static int id[maxn + 5];
		memset(id, -1, sizeof id);
		REP(j, 0, SZ(all) - 1) REP(k, all[j], all[j + 1]) id[k] = j;
		static int block_up[(block << 1) + 5], block_down[(block << 1) + 5];
		static int pos_up[maxn + 5], pos_down[maxn + 5];
		REP(j, 0, n) pos_up[j] = pos_down[j] = j;
		sort(pos_up, pos_up + n, [&](int x, int y) { return up[x] < up[y]; });
		sort(pos_down, pos_down + n, [&](int x, int y) { return down[x] < down[y]; });
		memset(block_up, oo, sizeof block_up);
		memset(block_down, oo, sizeof block_down);
		vector<que> ask;
		REP(j, i, to)
		{
			q[j].l = lower_bound(ALL(all), q[j].l) - all.begin();
			q[j].r = lower_bound(ALL(all), q[j].r) - all.begin();
			if (q[j].ty == 1) 
			{
				if (q[j].K > 0) REP(k, q[j].l, q[j].r) chkmin(block_up[k], q[j].K);
				else REP(k, q[j].l, q[j].r) chkmin(block_down[k], -q[j].K);
			}
			else
			{
				REP(k, q[j].l, q[j].r)
				{
					ask.pb(que(j, k, block_up[k], block_down[k]));
				}
			}
		}

		sort(ALL(ask), cmp_up);
		static LL sum[(block << 1) + 5], sum_in[(block << 1) + 5];
		static int cnt[(block << 1) + 5], cnt_in[(block << 1) + 5];
		memset(sum, 0, sizeof sum);
		memset(sum_in, 0, sizeof sum_in);
		memset(cnt, 0, sizeof cnt);
		memset(cnt_in, 0, sizeof cnt_in);
		REP(k, 0, n) if (~id[k])
		{
			++cnt[id[k]];
			if (down[k] < oo) ++cnt_in[id[k]];
		}
		int j = 0;
		for (auto u : ask)
		{
			while (j < n && up[pos_up[j]] < u.up) 
			{
				if (~id[pos_up[j]])
				{
					sum[id[pos_up[j]]] += up[pos_up[j]];
					--cnt[id[pos_up[j]]];
					if (down[pos_up[j]] < oo)
					{
						sum_in[id[pos_up[j]]] += up[pos_up[j]];
						--cnt_in[id[pos_up[j]]];
					}
				}
				++j;
			}
			if (u.up < oo)
			{
				if (u.down < oo)
				{
					ans[u.id] += sum[u.p] + (LL)cnt[u.p] * u.up;
				}
				else
				{
					ans[u.id] += sum_in[u.p] + (LL)cnt_in[u.p] * u.up;
				}
			}
			else
			{
				if (u.down < oo) ans[u.id] += sum[u.p];
				else ans[u.id] += sum_in[u.p];
			}
		}

		sort(ALL(ask), cmp_down);
		memset(sum, 0, sizeof sum);
		memset(sum_in, 0, sizeof sum_in);
		memset(cnt, 0, sizeof cnt);
		memset(cnt_in, 0, sizeof cnt_in);
		REP(k, 0, n) if (~id[k])
		{
			++cnt[id[k]];
			if (up[k] < oo) ++cnt_in[id[k]];
		}
		j = 0;
		for (auto u : ask)
		{
			while (j < n && down[pos_down[j]] < u.down) 
			{
				if (~id[pos_down[j]])
				{
					sum[id[pos_down[j]]] += down[pos_down[j]];
					--cnt[id[pos_down[j]]];
					if (up[pos_down[j]] < oo)
					{
						sum_in[id[pos_down[j]]] += down[pos_down[j]];
						--cnt_in[id[pos_down[j]]];
					}
				}
				++j;
			}
			if (u.down < oo)
			{
				if (u.up < oo)
				{
					ans[u.id] += sum[u.p] + (LL)cnt[u.p] * u.down;
				}
				else
				{
					ans[u.id] += sum_in[u.p] + (LL)cnt_in[u.p] * u.down;
				}
			}
			else
			{
				if (u.up < oo) ans[u.id] += sum[u.p];
				else ans[u.id] += sum_in[u.p];
			}
		}
		REP(k, 0, n) if (~id[k]) chkmin(up[k], block_up[id[k]]), chkmin(down[k], block_down[id[k]]);
	}
	REP(i, 0, qn) if (q[i].ty == 2) printf("%" LLFORMAT "d\n", ans[i]);
	return 0;
}