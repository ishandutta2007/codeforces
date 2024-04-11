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

const int maxn = 150100;

int n;
int p[maxn + 5], t[maxn + 5];
LL sumt;

int pos[maxn + 5];

inline bool cmp(int x, int y) { return (LL)t[x] * p[y] < (LL)t[y] * p[x]; }

LL Min[maxn + 5], Max[maxn + 5];

int N = 0;
pair<int, double> a[(maxn << 1) + 5];

inline double calc(int x, int y) { return (a[y].y - a[x].y) / (a[y].x - a[x].x); }

inline double cross(int x, int y, int z) { return (a[y].x - a[x].x) * (a[z].y - a[x].y) - (a[y].y - a[x].y) * (a[z].x - a[x].x); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n) scanf("%d", t + i);
	sumt = accumulate(t, t + n, 0LL);
	REP(i, 0, n) pos[i] = i;
	sort(pos, pos + n, cmp);
	LL sum = 0;
	for (int i = 0; i < n; )
	{
		int j = i;
		while (j < n && (LL)t[pos[i]] * p[pos[j]] == (LL)t[pos[j]] * p[pos[i]]) ++j;
		LL tmp = 0;
		REP(k, i, j) tmp += t[pos[k]], Min[pos[k]] = sum + t[pos[k]];
		sum += tmp;
		REP(k, i, j) Max[pos[k]] = sum;
		i = j;
	}
	N = 0;
	REP(i, 0, n) a[N++] = mp(p[i], (double)Min[i] * p[i]), a[N++] = mp(p[i], (double)Max[i] * p[i]);
	sort(a, a + N);
	static int stk[(maxn << 1) + 5];
	int tot = 0;
	double ret = sumt;
	for (int i = 0; i < N; )
	{
		int j = i;
		while (j < N && a[j].x == a[i].x) ++j;
		REP(k, i, j)
		{
			if (tot)
			{
				int l = 0, r = tot - 1;
				while (l < r)
				{
					int mid = (l + r) >> 1;
					if (calc(stk[mid], k) < calc(stk[mid + 1], k)) l = mid + 1;
					else r = mid;
				}
				chkmax(ret, calc(stk[l], k));
			}
		}
		REP(k, i, j)
		{
			while (tot > 1 && cross(stk[tot - 2], stk[tot - 1], k) <= 0) --tot;
			stk[tot++] = k;
		}
		i = j;
	}
	printf("%.15f\n", sumt / ret);
	return 0;
}