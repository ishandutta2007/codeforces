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

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

int cur[600][600], prev[600][600];
int a[300][300];
int n;

int getF(int prev, int d, int p1, int p2)
{
    int i1 = d - p1;
    int i2 = d - p2;
    int j1 = p1;
    int j2 = p2;
    
    if (i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0)
        return -inf;
    if (i1 >= n || i2 >= n || j1 >= n || j2 >= n)
        return -inf;
    
    int res = prev + a[i1][j1] + a[i2][j2];
    if (p1 == p2)
        res -= a[i1][j1];
    
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    
    for (int i = 0; i < 600; ++i)
        for (int j = 0; j < 600; ++j)
            prev[i][j] = -inf;
    
    prev[0][0] = a[0][0];
    
    for (int d = 0; d < 2 * n - 2; ++d)
    {
        for (int i = 0; i < 600; ++i)
            for (int j = 0; j < 600; ++j)
                cur[i][j] = -inf;
        
        int st = 0, fin = n;
        
        while (d + 1 - st >= n)
            ++st;
        st = max(st - 1, 0);
        
        for (int p1 = st; p1 <= fin; ++p1)
            for (int p2 = st; p2 <= fin; ++p2)
                for (int newp1 = p1; newp1 <= fin && newp1 <= p1 + 1; ++newp1)
                    for (int newp2 = p2; newp2 <= fin && newp2 <= p2 + 1; ++newp2)
                        cur[newp1][newp2] = max(cur[newp1][newp2], getF(prev[p1][p2], d + 1, newp1, newp2));
        
        for (int i = 0; i < 600; ++i)
            for (int j = 0; j < 600; ++j)
                prev[i][j] = cur[i][j];
    }
    
    int res = -inf;
    
    for (int i = 0; i < 2 * n; ++i)
            res = max(res, prev[i][i]);
    
    cout << res << endl;
                
    return 0;
}