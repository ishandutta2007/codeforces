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

const int maxn = 1000000, max0 = 1001;

int n;
pair<int, int> x[maxn + 5], xx[maxn + 5];
int pos[maxn + 5];

inline bool cmp(const int &x, const int &y)
{
	return ::x[x] < ::x[y];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	static int pos[maxn + 5];
	REP(i, 0, n) scanf("%d%d", &x[i].x, &x[i].y), xx[i] = x[i], x[i].x /= max0, x[i].y = (x[i].x & 1) ? -x[i].y : x[i].y, pos[i] = i;
	sort(pos, pos + n, cmp);
	REP(i, 0, n) 
	{
		printf("%d ", pos[i] + 1);
	}
	return 0;
}