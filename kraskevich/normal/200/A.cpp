#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

const int N = 2002;
int hi[N][N], lo[N][N], ok[N][N];

void init()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            lo[i][j] = hi[i][j] = j, ok[i][j] = 1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    init();
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        
        --x;
        --y;
        
        int res = 4000, resx, resy;
        
        int xl = 0;
        int xr = n - 1;
        
        for (int j = x; j >= 0; --j)
        {
            if (x - j > res)
                break;
                
            if (lo[j][y] >= 0)
            {
                
                int cur = x - j + y - lo[j][y];
            
                if (cur < res || cur == res && j < resx || cur == res && j == resx && lo[j][y] < resy)
                {
                    res = cur;
                    resx = j;
                    resy = lo[j][y];
                }
            }
            if (hi[j][y] >= 0)
            {
                int cur = x - j + hi[j][y] - y;
            
                if (cur < res || cur == res && j < resx || cur == res && j == resx && lo[j][y] < resy)
                {
                    res = cur;
                    resx = j;
                    resy = hi[j][y];
                }
            }
        }
        
        for (int j = x + 1; j < n; ++j)
        {
            if (j - x > res)
                break;
                
            if (lo[j][y] >= 0)
            {
                
                int cur = j - x + y - lo[j][y];
            
                if (cur < res || cur == res && j < resx || cur == res && j == resx && lo[j][y] < resy)
                {
                    res = cur;
                    resx = j;
                    resy = lo[j][y];
                }
            }
            if (hi[j][y] >= 0)
            {
                int cur = j - x + hi[j][y] - y;
            
                if (cur < res || cur == res && j < resx || cur == res && j == resx && lo[j][y] < resy)
                {
                    res = cur;
                    resx = j;
                    resy = hi[j][y];
                }
            }
        }
        
        ok[resx][resy] = 0;
        
        int cur = -1;
        
        for (int j = 0; j < m; ++j)
        {
            if (ok[resx][j])
                cur = j;
            lo[resx][j] = cur;
        }
        
        cur = -1;
        
        for (int j = m - 1; j >= 0; --j)
        {
            if (ok[resx][j])
                cur = j;
            hi[resx][j] = cur;
        }
        
        printf("%d %d\n", resx + 1, resy + 1);
    }
    
    
    return 0;
}