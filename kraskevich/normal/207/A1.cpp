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
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define PB push_back

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

const int N = 2001;
int dp0[N][N], dp1[N][N];
int anc0[N][N];
int anc1[N][N];
int a[2][N];
int k[N];

void rec(int i, int j, int mode)
{
    if (i == 0 && j == 0)
        return;
    
    if (mode == 0)
    {
        rec(i - 1, j, anc0[i][j]);
        cout << a[0][i] << " " << 1 << endl;
    }
    else
    {
        rec(i, j - 1, anc1[i][j]);
        cout << a[1][j] << " " << 2 << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int m, x, y;
        cin >> k[i] >> a[i][1] >> x >> y >> m;
        
        for (int j = 2; j <= k[i]; ++j)
            a[i][j] = ((i64)a[i][j - 1] * x + y) % m;
    }
    
    a[0][0] = -1;
    a[1][0] = -1;
    dp0[0][0] = 0;
    dp1[0][0] = 0;
    
    for (int i = 0; i <= k[0]; ++i)
        for (int j = 0; j <= k[1]; ++j)
        {
            if (i + j == 0)
                continue;
            
            if (i > 0)
            {
                int fi = dp0[i - 1][j] + (a[0][i] >= a[0][i - 1] ? 0 : 1);
                int fj = dp1[i - 1][j] + (a[0][i] >= a[1][j] ? 0 : 1);
                
                dp0[i][j] = min(fi, fj);
                if (fi <= fj)
                    anc0[i][j] = 0;
                else
                    anc0[i][j] = 1;
            }
            else
                dp0[i][j] = inf;
            
            if (j > 0)
            {
                int fi = dp0[i][j - 1] + (a[1][j] >= a[0][i] ? 0 : 1);
                int fj = dp1[i][j - 1] + (a[1][j] >= a[1][j - 1] ? 0 : 1);
                
                dp1[i][j] = min(fi, fj);
                if (fi <= fj)
                    anc1[i][j] = 0;
                else
                    anc1[i][j] = 1;
            }
            else
                dp1[i][j] = inf;
        }
    
    cout << min(dp1[k[0]][k[1]], dp0[k[0]][k[1]]) << endl;
    
    int mode = 0;
    if (dp1[k[0]][k[1]] < dp0[k[0]][k[1]])
        mode = 1;
        
    rec(k[0], k[1], mode);
    
    return 0;
}