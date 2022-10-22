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
const LL base = inf * 1000ll + 17;
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
    vec<LL> dp(6e6, 0);

    vec<bool> prime(6e6, 1);

    prime[0] = prime[1] = 0;

    for(LL i(2);i * i < 6e6;i++) {
        if(!prime[i]) continue;
        for(LL j(i * i);j < 6e6;j += i) {
            prime[j] = 0;
        }
    }

    for(LL i(2);i < 6e6;i++) {
        if(!prime[i]) continue;
        int c = 0;
        //cout << i << ' ';
        for(LL j(i);j < 6e6;j += i) {
            LL x = j;
            c = 0;
            while(x % i == 0) {
                c++;
                x /= i;
            }
            dp[j] += c;
        }
    }

    for(int i(1);i < 6e6;i++) {
        dp[i] += dp[i - 1];
    } 

    int t;
    scanf("%d", &t);

    for(int i(0);i < t;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%I64d\n", dp[a] - dp[b]);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}