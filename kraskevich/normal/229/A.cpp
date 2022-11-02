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
#include <fstream>
 
using namespace std;
 
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
 
typedef long long i64;

const int inf = 1000 * 1000 * 1000;
string s[100];
int dp[100][10000];
int n, m;

void init()
{
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 10000; ++j)
            dp[i][j] = inf;
}

void calc(int row)
{
    string t = s[row] + s[row] + s[row];
    int f = -1;
    
    for (int i = 0; i < t.length(); ++i)
    {
        if (t[i] == '1')
            f = i;
        if (f >= 0 && i >= m && i < 2 * m)
            dp[row][i - m] = i - f;
    }
    
    f = 3 * m;
    for (int i = t.length() - 1; i >= 0; --i)
    {
        if (t[i] == '1')
            f = i;
        if (f != 3 * m && i >= m && i < 2 * m)
            dp[row][i - m] = min(dp[row][i - m], f - i);
    }
}
             

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    
    init();
    for (int i = 0; i < n; ++i)
        calc(i);
    
    long long res = inf;
    
    for (int i = 0; i < m; ++i)
    {
        long long cur = 0;
        for (int row = 0; row < n; ++row)
            cur += (long long)dp[row][i];
        res = min(res, cur);
    }
    
    if (res == inf)
        res = -1;
    
    cout << res;
    
    return 0;
}