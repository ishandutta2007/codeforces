#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <vector>
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define SZ(x) (int((x).size()))
#define x first
#define y second
#define mp make_pair
using namespace std;
const int maxn = 1000;
int n;
int a[maxn + 5];
void init()
{
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", a + i);
}
vector<pair<int, int> > tmp;
void dfs(const int &x)
{
	int cnt = 0;
	if (a[0] != 1) ++cnt;
	int pos[maxn + 5];
	pos[a[0]] = 0;
    REP(i, 1, n) 
	{
		pos[a[i]] = i;
		if (abs(a[i] - a[i - 1]) != 1) ++cnt;
	}
    if (a[n - 1] != n) ++cnt;
    if (cnt > (x << 1)) return;
    if (!cnt)
    {
		printf("%d\n", SZ(tmp));
        for (int i = SZ(tmp) - 1; i >= 0; --i) printf("%d %d\n", tmp[i].x + 1, tmp[i].y);
		exit(0);
    }
	pos[0] = -1;
	pos[n + 1] = n;
	FOR(i, 0, n)
	{
		for (int j = -1; j <= 1; j += 2)
		{
			if (pos[i + j] <= pos[i] + 1) continue;
			REP(k, 0, 2)
			{
				if (pos[i] + k < 0 || pos[i + j] + k > n) continue;
				reverse(a + pos[i] + k, a + pos[i + j] + k); 
				tmp.pb(mp(pos[i] + k, pos[i + j] + k));
				dfs(x - 1);
				tmp.pop_back();
				reverse(a + pos[i] + k, a + pos[i + j] + k); 
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
	a[n] = n + 1;
    dfs(3);
    return 0;
}