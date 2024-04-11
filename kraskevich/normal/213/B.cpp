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
const double eps = 1e-7;
const int inf = (int)1e9;
const i64 mod = 1000 * 1000 * 1000 + 7;
int a[10];

i64 c[101][101];

void init()
{
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j)
            c[i][j] = 0;
            
    for (int i = 0; i <= 100; ++i)
        c[i][0] = 1;
    
    for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= 100; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j], c[i][j] %= mod;
}

i64 solve(int n)
{
    --n;
    
    i64 res = 0;
    
    for (int cur0 = 1; cur0 <= 9; ++cur0)
    {
        a[cur0]--;
        
        i64 dp[n + 1][11];
        
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= 10; ++j)
                dp[i][j] = 0;
        dp[0][0] = 1;
        
        for (int d = 0; d <= 9; ++d)
            for (int prev = 0; prev <= n; ++prev)
                for (int cur = max(0, a[d]); cur + prev <= n; ++cur)
                    dp[cur + prev][d + 1] += c[n - prev][cur] * dp[prev][d], dp[cur + prev][d + 1] %= mod;
    
        res += dp[n][10];
        res %= mod;
        a[cur0]++;
    }
                
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    init();
    
    int n;
    
    cin >> n;
    
    for (int i = 0; i < 10; ++i)
        cin >> a[i];
    
    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += solve(i), ans %= mod;
    
    cout << ans;
    
    cin >> n;
        
    return 0;
}