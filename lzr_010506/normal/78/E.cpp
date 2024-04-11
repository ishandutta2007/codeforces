#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define E Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 10005;
const int M = 1e5 + 10;
const int inf = 1 << 30;
struct Edge
{
	int v, to, next;
}e[N * 10];
struct Node
{
	int x, y, step;
};
int head[N], dis[N], cur[N], pre[N], num[N], n, cnt, S, T, vn, TT, q[M], h[N];
int sx, sy, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int flag[15][15], vis[15][15];
char mat1[15][15], mat2[15][15];
bool in(int x,int y)
{
	if(x < 1 || x > n || y < 1 || y > n) return false;
	return true;
}
void ins(int u, int v, int w)
{
    e[++ cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].v = w;
    head[u] = cnt;
}
void insert(int u, int v, int w)
{
    ins(u, v, w);
    ins(v, u, 0);
}
void bfs1()
{
	queue<Node> Q;
	Node now, New;
	now.x = sx;
	now.y = sy;
	now.step = 0;
	Q.push(now);
	memset(flag, 0x7f, sizeof(flag));
	memset(vis, 0, sizeof(vis));
	vis[now.x][now.y] = 1;
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		flag[now.x][now.y] = now.step;
		if(now.step > T) break;
		rep(i, 0, 3)
		{
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if(in(xx, yy) && mat1[xx][yy] != 'Y' && !vis[xx][yy])
			{
				New.x = xx;
				New.y = yy;
				New.step = now.step + 1;
				vis[xx][yy] = 1;
				Q.push(New);
			}
		}
	}
}
void bfs2(int i,int j)
{
	queue<Node> Q;
	Node now,New;
	now.x = i;
	now.y = j;
	now.step = 0;
	Q.push(now);
	memset(vis, 0, sizeof(vis));
	vis[now.x][now.y] = 1;
	while(!Q.empty())
	{
		now =   Q.front();
		Q.pop();
		if(now.step > TT) break;
		if(flag[now.x][now.y] < now.step) continue;
		if(flag[now.x][now.y] == now.step && (mat2[now.x][now.y] < '1' || mat2[now.x][now.y] > '9')) continue;
		if(mat2[now.x][now.y] >= '1' && mat2[now.x][now.y] <= '9')
		{
			if(now.x != i || now.y != j) insert((i - 1) * n + j, (now.x - 1) * n + now.y + n * n, inf);
			if(flag[now.x][now.y] == now.step) continue;
		}
		rep(i, 0, 3)
		{
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if(in(xx, yy) && mat1[xx][yy] != 'Y' && !vis[xx][yy])
			{
				New.x = xx;
				New.y = yy;
				New.step = now.step + 1;
				vis[xx][yy] = 1;
				Q.push(New);
			}
		}
	}
}


int bfs()
{
    int t = 0, w = 1;
    memset(h, -1, sizeof(h));
    h[S] = 0;
    q[0] = S;
    while(t != w)
    {
        int now = q[t ++];
        if(t == M) t = 0;
        for(int i = head[now]; i; i = e[i].next)
        {
            int y = e[i].to;
            if(h[y] == -1 && e[i].v)
            {
                h[y] = h[now] + 1;
                q[w ++] = y;
                if(w == M) w = 0;
            }
        }
    }
    if(h[T] == -1) return 0;
    else return 1;
}

int dfs(int x, int f)
{
    if(x == T) return f;
    int used = 0, w;
    for(int i = cur[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if(h[y] == h[x] + 1 && e[i].v)
        {
            w = dfs(y, min(e[i].v, f - used));
            used += w;
            e[i].v -= w;
            if(e[i].v) cur[x] = i;
            e[i ^ 1].v += w;
            if(used == f) return f;
        }
    }
    if(!used) h[x] = -1;
    return used;
}

int dinic()
{
    int ans = 0;
    while(bfs())
    {
        for(int i = 0; i <= T; i ++)
            cur[i] = head[i];
        ans += dfs(S, inf);
    }
    return ans;
}

int main()
{
	n = read();
	TT = read();
	S = 0;
	T = n * n + n * n + 1;
	vn = T + 1;
	cnt = 1;
	rep(i, 1, n)
	{
		scanf("%s", mat1[i] + 1);
		rep(j, 1, n)
		{
			if(mat1[i][j] >= '1' && mat1[i][j] <= '9')
				insert(S, (i - 1) * n + j, mat1[i][j] - '0');
			if(mat1[i][j] == 'Z') sx = i, sy = j;
		}
	}
	rep(i, 1, n)
	{
		scanf("%s", mat2[i] + 1);
		rep(j, 1, n)
       	{
            insert((i - 1) * n + j, (i - 1) * n + j + n * n, inf);
            if(mat2[i][j] >= '1' && mat2[i][j] <= '9')
                insert((i - 1) * n + j + n * n, T, mat2[i][j] - '0');
        }
	}
	bfs1();
	rep(i, 1, n)
		rep(j, 1, n)
			if(mat1[i][j] >= '1' && mat1[i][j] <= '9')
				bfs2(i, j);
	printf("%d\n", dinic());
	return 0;
}