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

const int maxn = 100100;

int work(vector<pair<int, int> > a, int lim)
{
	if (SZ(a) <= 1) return -oo;
	int an = SZ(a);
	sort(ALL(a));
	static int preMax[maxn + 5];
	preMax[0] = -oo;
	REP(i, 0, an) preMax[i + 1] = max(a[i].y, preMax[i]);
	int j = an;
	int ret = -oo;
	REP(i, 0, an)
	{
		while (j > 0 && a[i].x + a[j - 1].x > lim) --j;
		chkmax(ret, a[i].y + preMax[min(i, j)]);
	}
	return ret;
}

int n, lima, limb;
vector<pair<int, int> > a, b;

int ans = 0;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int Maxa = -oo, Maxb = -oo;
	scanf("%d%d%d", &n, &lima, &limb);
	REP(i, 0, n)
	{
		static char s[5];
		int w, p;
		scanf("%d%d%s", &w, &p, s);
		if (s[0] == 'C') 
		{
			if (p <= lima) chkmax(Maxa, w);
			a.pb(mp(p, w));
		}
		else
		{
			if (p <= limb) chkmax(Maxb, w);
			b.pb(mp(p, w));
		}
	}
	chkmax(ans, Maxa + Maxb);
	chkmax(ans, work(a, lima));
	chkmax(ans, work(b, limb));
	printf("%d\n", ans);
	return 0;
}