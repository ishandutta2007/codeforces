#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<int> factors(int x) {
    vector<int> res;
    for (int i = 2; i <= x; ++i) {
        if (x % i == 0) {
            res.PB(i);
        }
        while (x % i == 0) {
            x /= i;
        }
    }
    return res;
}

vector<int> f;

int p;

int pot(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            res = (res * (LL) a) % p;
        }
        a = (a * (LL) a) % p;
    }
    return res;
}

bool check(int x) {
    if (x < 2 || x > p - 1) {
        return false;
    }
    FORE (it, f) {
        if (pot(x, (p - 1) / *it) == 1) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    while (a && b) {
        a > b ? a %= b : b %= a;
    }
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    if (x == 2) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << x - 1 << endl;
        return 0;
    }
    if (factors(n + 1)[0] != n + 1) {
        cout << -1 << endl;
        return 0;
    }
    p = n + 1;
    f = factors(n);
    int g = 1;
    while (!check(g)) {
        g = rand() % p;
    }
    int res = -1;
    int c = 1;
    for (int i = 1; i < p; ++i) {
        c = (c * (LL) g) % p;
        if (gcd(p - 1, i) == 1) {
            if (x > c) {
                res = max(res, c + ((x - c - 1) / p) * p);
            }
        }
    }
    cout << res << endl;
}