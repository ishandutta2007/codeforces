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
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

bool solve()
{
    int n, m, b, mod;

    cin >> n >> m >> b >> mod;

    vec<int> a(n + 1);

    for(int i(1);i <= n;i++) {
        cin >> a[i];
    }

    vec< vec<int> > dp(n + 1, vec<int>(b + 1)), dp2;
    
    // dp[ ][ ][]

    dp[0][0] = 1 % mod;

    vec< int > sum(b + 1, 0);

    for(int i(1);i <= m;i++) {
        dp2.assign(n + 1, vec<int>(b + 1, 0));
        for(int c(0);c <= b;c++) sum[c] = dp[0][c] % mod;
        for(int j(1);j <= n;j++) {
            for(int c(0);c <= b;c++) {
                sum[c] = (sum[c] + dp[j][c]) % mod;
            }
            for(int c(0);c + a[j] <= b;c++) {
                dp2[j][c + a[j]] = (dp2[j][c + a[j]] + sum[c]) % mod;
            }
        }
        dp = dp2;
    }

    LL ans = 0;

    for(int i(0);i <= b;i++) {
        for(int j(1);j <= n;j++) {
            ans = (ans + dp[j][i]) % mod;
        }
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