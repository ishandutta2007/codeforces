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

const int maxn = 100000;

int ax, ay, bx, by, tx, ty;

inline double get_dis(double ax, double ay, double bx, double by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

int n;
double dis[maxn + 5], disa[maxn + 5], disb[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
	int n;
	double sum = 0;
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		dis[i] = get_dis(x, y, tx, ty);
		sum += dis[i] * 2;
		disa[i] = get_dis(x, y, ax, ay);
		disb[i] = get_dis(x, y, bx, by);
	}
	double ans = 1e100;
	static double sufa[maxn + 5], sufb[maxn + 5];
	sufa[0] = 0;
	sufb[0] = 0;
	REP(i, 0, n) 
	{
		sufa[i + 1] = min(sufa[i], disa[i] - dis[i]);
		sufb[i + 1] = min(sufb[i], disb[i] - dis[i]);
	}
	REP(i, 0, n)
	{
		chkmin(ans, sufa[i] + disb[i] - dis[i] + sum);
		chkmin(ans, sufb[i] + disa[i] - dis[i] + sum);
	}
	printf("%.15f\n", ans);
	return 0;
}