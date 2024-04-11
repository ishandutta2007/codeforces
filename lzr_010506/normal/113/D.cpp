#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define get(x, y) (x) > (y) ? id[y][x] : id[x][y]
const int N = 24;
const int INF = 1e9;
int tot, id[N][N];
bool b[N][N];
int d[N];
double a[N*N][N*N], p[N];
inline void add(int q,int w,int e,int r)
{
    b[get(q, w)][get(e, r)] = 1;
    b[get(e, r)][get(q, w)] = 1;
}
void gauss()
{
    for(int i = 1; i <= tot; i ++)
    {
        for(int k = i + 1; k <= tot; k ++)
        	if(abs(a[k][i]) > abs(a[i][i]))swap(a[k],a[i]);
        for(int j = tot + 1; j >= i; j --)
        	a[i][j] /= a[i][i];
        for(int k = i + 1; k <= tot; k ++)
            for(int j = tot + 1; j >= i; j --)
            	a[k][j] -= a[k][i] * a[i][j];
    }
    for(int i = tot; i; i --)
        for(int k = i - 1; k; k --)
        	a[k][tot + 1] -= a[k][i] * a[i][tot + 1];
}
int main()
{
    int n = read();
    int m = read();
    int x = read();
    int y = read();
    for(int i = 1; i <= m; i ++)
    {
        int x = read();
        int y = read();
        b[x][y] = b[y][x] = 1;
        d[x] ++;
        d[y] ++;
    }
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
        	id[i][j] = ++ tot;
    for(int o = 1; o <= n; o ++)
    {
        memset(a,0,sizeof(a));
        a[get(o,o)][tot + 1] = 1;
        for(int i = 1; i <= n; i ++)
        {
            a[get(i,i)][get(i,i)] = 1;
            for(int j = i + 1; j <= n; j ++)
            {
                int now = get(i, j);
                a[now][now] = p[i] * p[j] - 1;
                for(int k = 1; k <= n ; k ++)
                	a[now][get(i,k)] += b[j][k] * p[i] * (1 - p[j]) / d[j];
                for(int k = 1; k <= n; k ++)
                	a[now][get(k,j)] += b[i][k] * p[j] * (1 - p[i]) / d[i];
                for(int k = 1; k <= n; k ++)
                    for(int l = 1; l <= n; l ++)
                        a[now][get(k,l)] += b[i][k] * b[j][l] * (1 - p[i]) * (1 - p[j]) / d[i] / d[j];
            }
        }
        gauss();
        printf("%.6lf ",a[get(x,y)][tot+1]);
    }
    return 0;
}