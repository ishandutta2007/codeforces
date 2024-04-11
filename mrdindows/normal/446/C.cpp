#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000009; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


const int N = 300000 + 10;

// 1-indexed
template<class T>
class BIT {
    T bit[N];
    int n;

public:
    BIT() {
        n = N;
        memset(bit, 0, sizeof(bit));
    }

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            if (s >= MOD) s -= MOD;
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x) {
        if (x < MOD) x += MOD;
        x %= MOD;
        while (i <= n) {
            bit[i] += x;
            if (bit[i] >= MOD)
                bit[i] -= MOD;
            i += i & -i;
        }
    }
};

ll fib[N];
Pll coff[N];

void init() {
    coff[0] = Pll(0, 1);
    for (int i = 1; i < N; i++) {
        coff[i].first = coff[i - 1].second;
        coff[i].second = (coff[i - 1].first - coff[i - 1].second + MOD) % MOD;
    }
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= MOD) fib[i] -= MOD;
    }
}

BIT<ll> b1, b2, b3;

void update(int l, int r) {
    ll alpha = coff[l].first;
    ll beta = coff[l].second;
    ll a1 = (3 * alpha + 2 * beta) % MOD;
    ll a2 = (2 * alpha + beta) % MOD;

    b1.add(l, a1);
    b2.add(l, a2);
    b3.add(l, -1);

    b1.add(r, -a1);
    b2.add(r, -a2);
    b3.add(r, fib[r - l + 2]);
}

ll get(int idx) {
    ll a1 = b1.sum(idx) * fib[idx + 1];
    ll a2 = b2.sum(idx) * fib[idx];
    ll a3 = b3.sum(idx);
    return (a1 + a2 + a3) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();

    int n, m; scanf("%d%d", &n, &m);
    FOR(i, n) {
        int tmp; scanf("%d", &tmp);
        b3.add(i + 1, tmp);
    }

    map<int, Pll> mp;
    mp[0] = Pll(0, 0);
    FOR(i, m) {
        int t, l, r; scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            r++;
            update(l, r);
        }
        else {
            l--;
            ll a1 = get(r);
            ll a2 = get(l);
            int ans = ((a1 - a2) % MOD + MOD) % MOD;
            printf("%d\n", ans);
        }
    }
}