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
    os << ' ';
    return os;
}

bool solve()
{
    int n;
    cin >> n;

    vec<int> a(n);
    for(int i(0);i < n;i++) {
        scanf("%d", &a[i]);
    }

    int all = 0;
    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            if(a[i] > a[j]) {
                all++;
            }
        }
    }

    vec< vec<int> > dp(n, vec<int> (n, 0)), dp2 = dp;

    for(int i(1);i < n;i++) {
        for(int j(0);j < n;j++) {
            dp[i][j] = dp[i - 1][j] + (a[i] > j);
        }
    }

    for(int i(n - 2);i >= 0;i--) {
        for(int j(0);j < n;j++) {
            dp2[i][j] = dp2[i + 1][j] + (j > a[i]);
        }
    }

    int ans = inf, ans2 = 0;

    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            int until, after, x = a[i], y = a[j];
            until = after = 0;
            if(i + 1 <= j - 1) {
                until = dp2[i + 1][x] - dp2[j][x] + dp[j - 1][y] - dp[i][y];
                after = dp2[i + 1][y] - dp2[j][y] + dp[j - 1][x] - dp[i][x];
            }
            until += (a[i] > a[j]);
            after += (a[i] < a[j]);
            int tmp = all - until + after;
            if(tmp < ans) {
                ans = tmp;
                ans2 = 1;
            }else if(tmp == ans) {
                ans2++;
            }
        }
    }

    cout << ans << ' ' << ans2 << '\n';
    
    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}