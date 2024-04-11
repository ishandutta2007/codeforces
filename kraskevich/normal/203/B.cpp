#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define FORN for(int i = 0; i < n; ++i)
#define PB push_back
#define REP(i, l, r) for(int i = l; i <= r; ++i)

int a[1111][1111];

bool ok(int x, int y, int n)
{
    if(x < 0 || y < 0)
        return false;
    if(x + 3 > n || y + 3 > n)
        return false;
        
    int s = 0;
    for(int i = x; i < x + 3; ++i)
        for(int j = y; j < y + 3; ++j)
            s += a[i][j];
    if(s == 9)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            a[i][j] = 0;
    
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x][y] = 1;
        
        for(int xx = x - 4; xx <= x + 4; ++xx)
            for(int yy = y - 4; yy <= y + 4; ++yy)
                if(ok(xx, yy, n))
                {
                    cout << i + 1;
                    cin >> n;
                    return 0;
                }
    }
    
    cout << -1;
    
    return 0;
}