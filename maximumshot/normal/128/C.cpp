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

LL binpow(LL n, LL m) {
    if(m == 0) return 1ll;
    LL q = binpow(n, m / 2);
    q = (q * q) % base;
    if(m % 2) {
        return (q * n) % base;
    }else {
        return q;
    }
}

LL R(LL x) {
    return binpow(x, base - 2); 
}

LL fact[3030];

LL C(LL n, LL k) {
    if(k > n) return 0ll;
    return (((fact[n] * R(fact[k])) % base) * R(fact[n - k])) % base;
}

bool solve()
{
    fact[0] = 1ll;
    for(int i(1);i < 3030;i++) {
        fact[i] = (fact[i - 1] * 1ll * (LL)i) % base;
    }

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    // C[n - 1][2 * k] * C[m - 1][2 * k]

    LL v1, v2;

    v1 = C(n - 1, 2 * k);
    v2 = C(m - 1, 2 * k);

    printf("%I64d\n", (v1 * v2) % base);

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}