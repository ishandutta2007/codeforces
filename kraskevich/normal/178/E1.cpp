#include <iostream>
using namespace std;

int a[2000][2000];
int u[2000][2000];
int n;
int cur = 1;
int maxX = -1, minX = 2000, minY = 2000, maxY = -1;

void dfs(int x, int y)
{
     minY = min(y, minY);
     maxY = max(y, maxY);
     minX = min(minX, x);
     maxX = max(maxX, x);
     u[x][y] = cur;
     if(x > 0 && !u[x - 1][y] && a[x - 1][y] == 1)
          dfs(x - 1, y);
     if(x < n - 1 && !u[x + 1][y] && a[x + 1][y] == 1)
          dfs(x + 1, y);
     if(y > 0 && !u[x][y - 1] && a[x][y - 1] == 1)
          dfs(x, y - 1);
     if(y < n - 1 && !u[x][y + 1] && a[x][y + 1] == 1)
          dfs(x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    cin >> a[i][j];
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    u[i][j] = 0;
                    
    int sq = 0, ck = 0;
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    if(u[i][j] <= 0 && a[i][j] == 1)
                    {
                        maxX = -1, minX = 2000, minY = 2000, maxY = -1;
                        dfs(i, j);
                        if(u[maxX][maxY] == cur)
                                         ++sq;
                        else
                            ++ck;
                        ++cur;
                    }  
    
    cout << ck << " " << sq << endl;
    
    cin >> n;
    
    return 0;
}