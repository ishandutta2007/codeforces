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

int n;
pair<int, int> a[maxn + 5];

LL Maxsqr[maxn + 5];
int Max[maxn + 5], Min[maxn + 5];

LL val[maxn + 5];

inline bool work(const LL &x)
{
	static int pre[maxn + 5];
	int lst = -1;
	REP(i, 0, n + 1)
	{
		pre[i] = lst;
		if (i < n && val[i] <= x) lst = i;
	}
	int lim = n - 1;
	LL pre_Maxsqr = LLONG_MIN;
	int pre_Max = -oo;
	int pre_Min = oo;
	int j = 0;
	REP(i, 0, n)
	{
		while (lim >= 0 && (LL)a[lim].x * a[lim].x + pre_Maxsqr > x) --lim;
		if (i > lim) return 0;
		while (j < n && (LL)(a[j].x - a[i].x) * (a[j].x - a[i].x) <= x) ++j;
		int nxt = pre[min(j, lim + 1)] + 1;
		if (nxt > i && (LL)a[nxt - 1].x * a[nxt - 1].x + pre_Maxsqr <= x)
		{
			LL tot_Maxsqr = max(pre_Maxsqr, Maxsqr[nxt]);
			int tot_Max = max(pre_Max, Max[nxt]);
			int tot_Min = min(pre_Min, Min[nxt]);
			if (tot_Maxsqr + (LL)a[i].x * a[i].x <= x && ((tot_Max <= tot_Min) || (LL)(tot_Max - tot_Min) * (tot_Max - tot_Min) <= x)) return 1;
		}
		chkmax(pre_Maxsqr, (LL)a[i].y * a[i].y);
		chkmax(pre_Max, a[i].y);
		chkmin(pre_Min, a[i].y);
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int Maxy = -oo, Miny = oo;
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), chkmax(Maxy, a[i].y), chkmin(Miny, a[i].y);
	sort(a, a + n);
	Maxsqr[n] = LLONG_MIN;
	Max[n] = -oo;
	Min[n] = oo;
	for (int i = n - 1; i >= 0; --i) 
	{
		Maxsqr[i] = Maxsqr[i + 1];
		Max[i] = Max[i + 1];
		Min[i] = Min[i + 1];
		chkmax(Maxsqr[i], (LL)a[i].y * a[i].y);
		chkmax(Max[i], a[i].y);
		chkmin(Min[i], a[i].y);
		val[i] = Maxsqr[i + 1] + (LL)a[i].x * a[i].x;
	}
	LL l = 0, r = (LL)(Maxy - Miny) * (Maxy - Miny);
	while (l < r)
	{
		LL mid = (l + r) >> 1;
		if (work(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}