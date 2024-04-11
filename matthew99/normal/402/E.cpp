#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 2000;

int n;

template<typename T> T &Read(T &x)
{
    static char c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) (x *= 10) += c - '0';
    return x;
}

bool f[maxn + 5][maxn + 5];

int dfn[maxn + 5], low[maxn + 5];
int tot = 0;

bool flag;

void dfs(const int &x)
{
    if (!flag) return;
    dfn[x] = low[x] = tot++;
    REP(y, 0, n)
        if (f[x][y])
        {
            if (dfn[y] == -1) dfs(y), low[x] = min(low[x], low[y]);
            else low[x] = min(low[x], dfn[y]);
        }
    if ((low[x] == dfn[x]) && x)
    {
        flag = 0;
        return;
    }
}

int now;

int col[maxn + 5];

bool dfs0(const int &x, const int &c = 0)
{
    col[x] = c;
    REP(y, 0, n)
        if (f[x][y])
        {
            if ((col[y] == -1 && !dfs0(y, (c + 1) % now)) || (col[y] != (c + 1) % now)) return 0;
        }
    return 1;
}
    
int main()
{
#ifndef ONLINE_JUDGE
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
#endif
    int T = 1;
    while (T--)
    {
        Read(n);
        REP(i, 0, n) REP(j, 0, n)
        {
            int x;
            Read(x);
            f[i][j] = !!x;
        }
        if (n == 1)
        {
            puts(f[0][0] ? "YES" : "NO");
            continue;
        }
        memset(dfn, -1, sizeof dfn);
        tot = 0;
        int cnt = 0;
        flag = 1;
        REP(i, 0, n)
        {
            if (dfn[i] == -1) 
            {
                ++cnt;
                if (cnt > 1)
                {
                    flag = 0;
                    break;
                }
                dfs(i);
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}