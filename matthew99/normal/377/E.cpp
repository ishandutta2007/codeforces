#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (LL i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (LL((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const LL oo = 0x3f3f3f3f;

const LL maxn = 200000, max0 = 1e9;

LL n;
LL s;
pair<LL, LL> a[maxn + 5];

LL stx[maxn + 5], k[maxn + 5];
LL sty[maxn + 5];
LL tot = 0;

LL ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%I64d%I64d", &n, &s);
	ans = s;
	REP(i, 0, n) scanf("%I64d%I64d", &a[i].x, &a[i].y);
	sort(a, a + n);
	REP(i, 0, n)
	{
		if (i && a[i].x == a[i - 1].x) continue;
		if (!tot)
		{
			if (!a[i].y)
			{
				stx[tot] = 0, sty[tot] = 0, k[tot] = a[i].x;
				chkmin(ans, (s + a[i].x - 1) / a[i].x);
				++tot;
			}
		}
		else
		{
			LL tmp = upper_bound(sty, sty + tot, a[i].y) - sty - 1;
			LL Minx = oo;
			LL Miny = -1;
			if (tmp + 1 != tot) Minx = stx[tmp + 1], Miny = sty[tmp + 1];
			LL lyc = stx[tmp] + (a[i].y - sty[tmp] + k[tmp] - 1) / k[tmp];
			if (chkmin(Minx, lyc)) Miny = sty[tmp] + (lyc - stx[tmp]) * k[tmp];
			assert(Miny >= a[i].y);
			Miny -= a[i].y;
			chkmin(ans, Minx + (s - Miny + a[i].x - 1) / a[i].x);
			while (tot)
			{
				if (stx[tot - 1] < Minx) break;
				if (LL(stx[tot - 1] - Minx) * a[i].x + Miny < sty[tot - 1]) break;
				--tot;
			}
			if (!tot) stx[tot] = Minx, sty[tot] = Miny, k[tot] = a[i].x, ++tot;
			else
			{
				if (k[tot - 1] == a[i].x) continue;
				if (LL(max0 - Minx) * a[i].x + Miny <= LL(max0 - stx[tot - 1]) * k[tot - 1] + sty[tot - 1]) continue;
				LL l = Minx, r = max0;
				while (l < r)
				{
					LL mid = (l + r) >> 1;
					if (LL(mid - Minx) * a[i].x + Miny < LL(mid - stx[tot - 1]) * k[tot - 1] + sty[tot - 1]) l = mid + 1;
					else r = mid;
				}
				stx[tot] = l, sty[tot] = LL(l - Minx) * a[i].x + Miny, k[tot] = a[i].x;
				++tot;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}