#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>
#include <functional>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f, Mod = 1e9 + 7, maxabs = 1e6;

const double eps = 1e-8;

const int maxn = 100000;
int n;
pair<pair<int, int>, pair<int, int> > all[maxn + 5];
double ans = 0;

double work()
{
	double ans = 0;
	REP(i, 0, n)
		if (all[i].x.x > all[i].x.y) swap(all[i].x.x, all[i].x.y), swap(all[i].y.x, all[i].y.y);;
	sort(all, all + n);
	double yyt = 0;
	double sum = 0;
	double sum0 = 0;
	static double up[(maxabs << 1) + 5], down[(maxabs << 1) + 5];
	REP(i, -maxabs, maxabs + 1) up[i + maxabs] = -maxabs - 1, down[i + maxabs] = maxabs + 1;
	REP(i, 0, n)
		REP(j, all[i].x.x, all[i].x.y + 1)
		{
			if (all[i].x.x == all[i].x.y)
			{
				up[j + maxabs] = max(up[j + maxabs], (double)all[i].y.y);
				down[j + maxabs] = min(down[j + maxabs], (double)all[i].y.x);
			}
			else
			{
				double x = (all[i].y.x * double(all[i].x.y - j) + all[i].y.y * double(j - all[i].x.x)) / (all[i].x.y - all[i].x.x);
				up[j + maxabs] = max(up[j + maxabs], x);
				down[j + maxabs] = min(down[j + maxabs], x);
			}
		}
	REP(i, -maxabs, maxabs + 1)
	{
		int U = floor(up[i + maxabs] + eps), D = floor(down[i + maxabs] + 1 - eps);
		if (U < D) continue;
		ans += double(U - D + 1) * ((double)i * i * yyt + sum);
		ans -= double(U - D + 1) * ((double)2 * i * sum0);
		sum += double(U - D + 1) * i * i;
		sum0 += double(U - D + 1) * i;
		yyt += U - D + 1;
	}
	ans *= 2;
	ans /= yyt * (yyt - 1);
	return ans; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		static int x, y;
		scanf("%d%d", &x, &y);
		all[(i + 1) % n].x.x = x;
		all[(i + 1) % n].y.x = y;
		all[i].x.y = x;
		all[i].y.y = y;
	}
	ans += work();
	REP(i, 0, n) swap(all[i].x, all[i].y);
	ans += work();
	ans /= 2;
	printf("%.15lf\n", ans);
	return 0;
}