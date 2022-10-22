#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf / 10ll;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n1, n2, k1, k2;

    cin >> n1 >> n2 >> k1 >> k2;

    vec< vec< vec<LL> > > dp(n1 + 1, vec< vec<LL> >(n2 + 1, vec<LL>(2, 0)));
     
    dp[0][0][0] = dp[0][0][1] = 1;

    for(int i(0);i <= n1;i++)
    {
        for(int j(0);j <= n2;j++)
        {
            for(int k(1);k <= min(i, k1);k++) dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % base;
            for(int k(1);k <= min(j, k2);k++) dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % base;
        }
    }

    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % base << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}