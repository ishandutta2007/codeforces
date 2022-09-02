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

const int maxn = 200100;

int n;

int p[maxn + 5];

vector<int> alla[3], allb[3];
bool vis[maxn + 5];

bool cmp(int x, int y) { return p[x] > p[y]; }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x), --x;
		alla[x].pb(i);
	}
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x), --x;
		allb[x].pb(i);
	}
	REP(i, 0, 3) sort(ALL(alla[i]), cmp);
	REP(i, 0, 3) sort(ALL(allb[i]), cmp);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int x;
		scanf("%d", &x), --x;
		while (!alla[x].empty() && vis[alla[x].back()]) alla[x].pop_back();
		while (!allb[x].empty() && vis[allb[x].back()]) allb[x].pop_back();
		if (alla[x].empty() && allb[x].empty()) printf("-1 ");
		else
		{
			int tmp = -1;
			if (alla[x].empty()) tmp = allb[x].back();
			else if (allb[x].empty()) tmp = alla[x].back();
			else if (p[alla[x].back()] < p[allb[x].back()]) tmp = alla[x].back();
			else tmp = allb[x].back();
			printf("%d ", p[tmp]);
			vis[tmp] = 1;
		}
	}
	return 0;
}