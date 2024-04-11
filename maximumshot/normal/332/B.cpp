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
    int n, k;

    scanf("%d %d", &n, &k);

    vec<int> a(n + 1);

    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i]);
    }

    vec<LL> sum(n + 1);

    for(int i(1);i <= n;i++) {
        sum[i] = sum[i - 1] + a[i]; 
    }

    vec<LL> b(n + 1);

    for(int i(k);i <= n;i++) {
        b[i] = sum[i] - sum[i - k];
    }

    vec<LL> dp(n + 1, 0), mx(n + 1, -inf64);
    vec<int> id(n + 1, -1);

    for(int i(1);i <= n;i++) {
        mx[i] = mx[i - 1];
        id[i] = id[i - 1];
        if(b[i] > mx[i]) {
            mx[i] = b[i];
            id[i] = i;
        }
    }

    dp[k] = b[k];

    LL ans = -inf64;
    int A, B;
    A = B = -1;

    for(int i(2 * k);i <= n;i++) {
        dp[i] = b[i] + mx[i - k];
        if(ans < dp[i]) {
            ans = dp[i];
            A = id[i - k];
            B = i;
        }
    }

    cout << A - k + 1 << ' ' << B - k + 1 << '\n';
    
    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}