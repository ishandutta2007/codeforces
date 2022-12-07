#include <bits/stdc++.h>
#define N 3010
using namespace std;

struct Edge
{
	int next, to;
}e[N << 1];
int head[N], n, m, cnt, a[N], b[N];
int s1, s2, l1, l2, t1, t2;
int dis[N][N], vis[N];

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void ins(int u, int v)
{
	e[++ cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void insert(int u, int v)
{
	ins(u, v);
	ins(v, u);
}

void bfs()  
{  
    memset(dis, 0, sizeof(dis));  
    for(int i = 1; i <= n; i++)  
    {  
        memset(vis, false, sizeof(vis));  
        queue <int> q;  
        vis[i] = true;  
        q.push(i);  
        while(!q.empty())  
        {  
            int u = q.front();  
            q.pop();  
            for(int j = head[u]; j; j = e[j].next)
            {  
                int v = e[j].to;  
                if(!vis[v])  
                {  
                    vis[v] = true;  
                    dis[i][v] = dis[i][u] + 1;  
                    q.push(v); 
                }  
            }  
        }  
    }  
}  

int main()
{
	n = read();
	m = read();
	for(int i = 1; i <= m; i ++)
	{
		int u, v;
		u = read();
		v = read();
		insert(u, v);
	}
	s1 = read();
	t1 = read();
	l1 = read();
	s2 = read();
	t2 = read();
	l2 = read();
	bfs();
	if(!(dis[s1][t1] <= l1 && dis[s2][t2] <= l2))  
    {  
        printf("-1\n");  
        return 0;  
    }  
    int tmp = dis[s1][t1] + dis[s2][t2];  
    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= n; j++)  
        {  
            if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)  
                tmp = min(tmp, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[s2][i] + dis[j][t2]);  
            if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[t2][i] + dis[i][j] + dis[i][s2] <= l2)  
                tmp = min(tmp, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[t2][i] + dis[i][s2]);  
            if(dis[t1][i] + dis[i][j] + dis[j][s1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)  
                tmp = min(tmp, dis[t1][i] + dis[i][j] + dis[j][s1] + dis[s2][i] + dis[j][t2]);  
            if(dis[t1][i] + dis[i][j] + dis[j][s1] <= l1 && dis[t2][i] + dis[i][j] + dis[j][s2] <= l2)  
                tmp = min(tmp, dis[t1][i] + dis[i][j] + dis[j][s1] + dis[t2][i] + dis[j][s2]);  
        }  
    printf("%d\n", m - tmp);  
	return 0;
}