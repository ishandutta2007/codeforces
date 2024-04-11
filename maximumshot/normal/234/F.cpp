#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <cstring>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    vec< int > h(n + 1);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &h[i]);
    }

    LL dp[220][2][40400];

    for(int i = 0;i <= n;i++) 
        for(int j = 0;j < 40400;j++) 
            dp[i][0][j] = dp[i][1][j] = inf64;
    
    // red

    int s = h[1];

    dp[1][0][s] = dp[1][1][0] = 0;

    for(int i = 2;i <= n;i++) {
        s += h[i];
        for(int sum = 0;sum + h[i] <= s;sum++) {
            int ost = s - sum - h[i];
            if(ost > b) continue;
            if(sum + h[i] > a) continue;
            dp[i][0][sum + h[i]] = min(dp[i][0][sum + h[i]], dp[i - 1][0][sum]);
            dp[i][0][sum + h[i]] = min(dp[i][0][sum + h[i]], dp[i - 1][1][sum] + min(h[i - 1], h[i]));
        }
        for(int sum = 0;sum <= s;sum++) {
            int ost = s - sum;
            if(ost > b) continue;
            dp[i][1][sum] = min(dp[i][1][sum], dp[i - 1][1][sum]);
            dp[i][1][sum] = min(dp[i][1][sum], dp[i - 1][0][sum] + min(h[i], h[i - 1]));
        }
    }

    LL ans = inf64;

    for(int i = 0;i <= a;i++) {
        for(int j = 0;j < 2;j++) {
            if(s - i <= b) ans = min(ans, dp[n][j][i]);
        }
    }

    cout << (ans == inf64?-1 : ans) << '\n';

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}