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

const double eps = 1e-14;

const int maxq = 100100;

const int maxabs = 1000000;

int qn;
LL m;

int n;
int a[maxq + 5], b[maxq + 5];
double rat[maxq + 5];

set<pair<int, int> > all;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%" LLFORMAT "d", &qn, &m);
	n = 0;
	int lst = 0;
	REP(i, 1, qn + 1)
	{
		int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y);
		(x += lst) %= maxabs;
		(y += lst) %= maxabs;
		++x, ++y;
		if (ty == 1)
		{
			a[n] = x, b[n] = y;
			rat[n] = (double)a[n] / b[n];
			auto to_add = mp(a[n], n);
			if (all.empty()) all.insert(to_add);
			else
			{
				auto tmp = all.lower_bound(to_add);
				auto from = tmp, to = tmp;
				if (to == all.end() || rat[to->y] < rat[n])
				{
					while (from != all.begin())
					{
						--from;
						if (rat[from->y] > rat[n]) 
						{
							++from;
							break;
						}
					}
					all.erase(from, to);
					all.insert(to_add);
				}
			}
			++n;
		}
		else
		{
			if (all.empty())
			{
				puts("NO");
				continue;
			}
			int r = y / x;
			auto tmp = all.upper_bound(mp(r, oo));
			double ans = 0;
			if (tmp == all.begin())
			{
				double t = min((double)x, (double)m / b[tmp->y]);
				ans = t * a[tmp->y];
			}
			else if (tmp == all.end())
			{
				--tmp;
				double t = min((double)x, (double)m / b[tmp->y]);
				ans = t * a[tmp->y];
			}
			else
			{
				auto pre = tmp;
				--pre;
				int a0 = a[pre->y], a1 = a[tmp->y];
				int b0 = b[pre->y], b1 = b[tmp->y];
				double t0 = 0, t1 = 0;
				if ((LL)b0 * x > m) t0 = (double)m / b0, t1 = 0;
				else if ((LL)b1 * x <= m) t0 = 0, t1 = x;
				else
				{
					t0 = double(m - (LL)b1 * x) / (b0 - b1);
					t1 = x - t0;
				}
				ans = t0 * a0 + t1 * a1;
			}
			bool ret = (ans / y > (1 - eps));
			if (ret) puts("YES"), lst = i;
			else puts("NO");
		}
	}
	return 0;
}