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
#include <iomanip>

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
    string a, b;

    cin >> a >> b;

    int n = (int)a.size();
    int m = (int)b.size();

    vec< vec<LL> > dp(n + 2, vec<LL>(m + 2));

    a = "#" + a;
    b = "#" + b;
    LL ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i] == b[j]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1) % base;
            }
            dp[i][j + 1] = dp[i][j];
        }
        ans = (ans + dp[i][m]) % base;
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}