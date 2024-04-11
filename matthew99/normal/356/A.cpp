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

const int maxn = 300000, maxm = 300000;

int n, m;
int ans[maxn + 5];

struct data
{
	int l, r, v;
};

data b[maxm + 5];

vector<int> add[maxn + 5];
vector<int> del[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m) scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].v), --b[i].l, --b[i].v, add[b[i].l].pb(i), del[b[i].r].pb(i);
	set<int> now;
	REP(i, 0, n)
	{
		for (auto x : add[i]) now.insert(x);
		for (auto x : del[i]) now.erase(x);
		int ans = -1;
		for (auto x : now)
		{
			if (b[x].v != i)
			{
				ans = b[x].v;
				break;
			}
		}
		printf("%d ", ans + 1);
	}
	return 0;
}