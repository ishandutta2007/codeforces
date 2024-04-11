#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

int n, m;
vec< string > mat;

void dfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(mat[x][y] == '.') return;

    if((mat[x - 1][y] == '.' && mat[x - 1][y - 1] == '.' && mat[x][y - 1] == '.')
        || (mat[x - 1][y] == '.' && mat[x - 1][y + 1] == '.' && mat[x][y + 1] == '.')
        || (mat[x + 1][y] == '.' && mat[x][y + 1] == '.' && mat[x + 1][y + 1] == '.')
        || (mat[x + 1][y] == '.' && mat[x + 1][y - 1] == '.' && mat[x][y - 1] == '.')) 
    {
        mat[x][y] = '.';
        dfs(x - 1, y - 1);
        dfs(x - 1, y);
        dfs(x - 1, y + 1);  
        dfs(x, y - 1);
        dfs(x, y + 1);
        dfs(x + 1, y - 1);
        dfs(x + 1, y);
        dfs(x + 1, y + 1);
    }
}

bool solve()
{
    scanf("%d%d", &n, &m);

    mat.resize(n + 2, string(m + 2, '*'));
    for(int i(1);i <= n;i++)
    {
        char C;
        mat[i].resize(m);
        for(int j(1);j <= m;j++)
        {
            scanf(" %c", &C);
            mat[i][j] = C;
        }
    }

    for(int i(1);i <= n;i++)
        for(int j(1);j <= m;j++)
            dfs(i, j);

    for(int i(1);i <= n;i++)
    {
        for(int j(1);j <= m;j++)
            printf("%c", mat[i][j]);
        puts("");
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}