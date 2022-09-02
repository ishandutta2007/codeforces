#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxl = 1e6;

char s[maxl + 5], tmp[maxl + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	int m;
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static int k, d;
		scanf("%d%d", &k, &d);
		static int nxt[maxl + 5];
		static bool vis[maxl + 5];
		static vector<int> all[maxl + 5];
		static pair<int, int> pos[maxl + 5];
		static bool type[maxl + 5];
		int cur = 0;
		REP(i, 0, n) vis[i] = 0;
		REP(i, 0, d)
			for (int j = i; j < k; j += d)
				nxt[j] = (cur++) - 1;
		for (int i = k - 1; i >= 0; --i)	
		{
			if (vis[i]) continue;
			int j = i;
			all[i].clear();
			do
			{
				pos[j] = mp(i, SZ(all[i]));
				all[i].pb(j);
				vis[j] = 1;
				j = nxt[j];
			}while (j != -1 && j != i);
			if (j == -1) all[i].pb(-1);
			type[i] = j == -1;
		}
		REP(i, 0, n) tmp[i] = s[i];
		REP(i, 0, n)
		{
			int time = min(n - k + 1, n - i);
			int start = max(0, i - k + 1);
			int id0 = pos[i - start].x, id1 = pos[i - start].y;
			if (type[id0]) time = min(time, SZ(all[id0]) - id1 - 1);
			s[start + time + all[id0][(id1 + time) % SZ(all[id0])]] = tmp[i];
		}
		printf("%s\n", s);
	}
	return 0;
}