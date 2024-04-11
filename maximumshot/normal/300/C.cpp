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

bool is_good(const LL & x, const int & a, const int & b) {
    LL val = x;
    while(val) {
        if(val % 10ll != a && val % 10ll != b) {
            return 0;
        } 
        val /= 10;
    }
    return 1;
}

LL binpow(int n, int m) {
    if(m == 0) return 1ll;
    LL q = binpow(n, m / 2);
    q = (q * q) % base;
    if(m % 2) {
        return (q * (LL)n) % base;
    }else {
        return q;
    }
}

LL R(const LL & x) {
    return binpow(x, base - 2); 
}

vec<LL> fact(1e6 + 10);

LL C(const int & n, const int & k) {
    return ((fact[n] * R(fact[n - k])) % base * R(fact[k])) % base;
}

bool solve()
{
    fact[0] = 1ll;
    for(LL i(1);i <= 1e6;i++) {
        fact[i] = (fact[i - 1] * i) % base;
    }

    int a, b, n;

    scanf("%d %d %d", &a, &b, &n);

    int ans = 0;

    for(int i(0);i <= n;i++) {
        LL sum = i * a + (n - i) * b;
        if(!is_good(sum, a, b)) continue;
        ans = (ans + C(n, i)) % base;
    }

    printf("%d\n", ans);

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}