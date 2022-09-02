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

pair<int, int> a[4], b[4];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int Maxa[2] = {-oo, -oo}, Mina[2] = {oo, oo};
	REP(i, 0, 4) 
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		chkmax(Maxa[0], a[i].x);
		chkmax(Maxa[1], a[i].y);
		chkmin(Mina[0], a[i].x);
		chkmin(Mina[1], a[i].y);
	}
	int Maxb[2] = {-oo, -oo}, Minb[2] = {oo, oo};
	REP(i, 0, 4) 
	{
		scanf("%d%d", &b[i].x, &b[i].y);
		chkmax(Maxb[0], b[i].x - b[i].y);
		chkmax(Maxb[1], b[i].x + b[i].y);
		chkmin(Minb[0], b[i].x - b[i].y);
		chkmin(Minb[1], b[i].x + b[i].y);
	}
	REP(i, -100, 101) REP(j, -100, 101)
	{
		if ((i - Maxa[0]) * (i - Mina[0]) > 0) continue;
		if ((j - Maxa[1]) * (j - Mina[1]) > 0) continue;
		if ((i - j - Maxb[0]) * (i - j - Minb[0]) > 0) continue;
		if ((i + j - Maxb[1]) * (i + j - Minb[1]) > 0) continue;
		puts("YES");
		exit(0);
	}
	puts("NO");
	return 0;
}