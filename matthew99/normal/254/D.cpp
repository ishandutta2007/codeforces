#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
using namespace std;
typedef long long LL;
const int oo = 0x3f3f3f3f;
const int maxn = 1000, max0 = 300;
int n, m, d;
char c[maxn + 5][maxn + 5];
int id[maxn + 5][maxn + 5];
pair<int, int> pos[max0 + 5], place[max0 + 5];
int tot = 0;
int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void BFS(const int &x, const int &y, pair<int, int> (&q)[max0 + 5], int &tot)
{
    static bool vis[maxn + 5][maxn + 5] = {{0}};
    static int dis[max0 + 5];
    tot = 0;
    dis[tot] = 0;
    q[tot++] = mp(x, y);
    vis[x][y] = 1;
    for (int i = 0; i < tot; ++i)
    {
        const pair<int, int> &x = q[i];
        if (dis[i] >= d) break;
        REP(j, 0, 4)
        {
            int u = x.x + walk[j][0], v = x.y + walk[j][1];
            if (u < 0 || v < 0 || u >= n || v >= m || c[u][v] == 'X' || vis[u][v]) continue;
            vis[u][v] = 1;
            dis[tot] = dis[i] + 1;
            q[tot++] = mp(u, v);
        }
    }
	REP(i, 0, tot) vis[q[i].x][q[i].y] = 0;
}
int main()
{
//#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//#endif
    scanf("%d%d%d", &n, &m, &d);
    REP(i, 0, n) scanf("%s", c[i]);
    REP(i, 0, n)
        REP(j, 0, m)
            if (c[i][j] == 'R')
            {
                if (tot >= max0) EXIT("-1\n");
                pos[id[i][j] = tot++] = mp(i, j);
            }
	static pair<int, int> q0[max0 + 5];
    int tot0 = 0;
    BFS(pos[0].x, pos[0].y, q0, tot0);
	REP(i, 0, tot0)
	{
		static pair<int, int> q1[max0 + 5];
		int tot1 = 0;
		BFS(q0[i].x, q0[i].y, q1, tot1);
		int yyt = 0;
		static bool vis[max0 + 5];
		memset(vis, 0, sizeof vis);
		REP(j, 0, tot1)
			if (c[q1[j].x][q1[j].y] == 'R' && !vis[id[q1[j].x][q1[j].y]])
			{
				vis[id[q1[j].x][q1[j].y]] = 1;
				++yyt;
			}
		if (yyt == tot) 
		{
			REP(k, 0, n)
				REP(j, 0, m)
					if (c[k][j] != 'X' && k != q0[i].x && j != q0[i].y) EXIT("%d %d %d %d\n", q0[i].x + 1, q0[i].y + 1, k + 1, j + 1);
			EXIT("-1\n");
		}
		int tmp = -1;
		REP(j, 0, tot)
			if (!vis[j])
			{
				tmp = j;
				break;
			}
		BFS(pos[tmp].x, pos[tmp].y, q1, tot1);
		REP(j, 0, tot1)
		{
			static pair<int, int> q2[max0 + 5];
			int tot2 = 0;
			BFS(q1[j].x, q1[j].y, q2, tot2);
			static bool vis0[max0 + 5];
			memcpy(vis0, vis, sizeof vis0);
			int pig = yyt;		
			REP(k, 0, tot2)
				if (c[q2[k].x][q2[k].y] == 'R' && !vis[id[q2[k].x][q2[k].y]])
				{
					vis[id[q2[k].x][q2[k].y]] = 1;
					++yyt;
				}
			if (yyt == tot) EXIT("%d %d %d %d\n", q0[i].x + 1, q0[i].y + 1, q1[j].x + 1, q1[j].y + 1);
			memcpy(vis, vis0, sizeof vis);
			yyt = pig;
		}
	}
    printf("-1\n");
    return 0;
}