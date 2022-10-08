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

struct Matrix {
    LL t[2][2];

    LL* operator[] (int x) {
        return t[x];
    }

    LL const* operator[] (int x) const {
        return t[x];
    }

    Matrix() {
        ZERO(t);
    }
};

LL m;

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int k = 0; k < 2; ++k) {
            for (int j = 0; j < 2; ++j) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
    }
    return result;
}

int main() {
    LL l, r, k;
    cin >> m >> l >> r >> k;
    LL len = r - l + 1;

    // LL mn = len / k;
    // LL mx = len / (k - 1);

    LL x = 1;

    for (LL i = 1; i <= 1000000; ++i) {
        if (r / i - (l - 1) / i >= k) {
            x = max(x, i);
        }
    }

    for (LL c = 1; c <= 1000000 && c <= r; ++c) {
        LL y = r / c;
        if (r / y - (l - 1) / y >= k) {
            x = max(x, y);
        }
    }

    Matrix a;
    a[0][0] = a[1][0] = a[0][1] = 1 % m;
    Matrix res;
    res[0][0] = res[1][1] = 1 % m;

    for (; x > 0; x >>= 1) {
        if (x & 1) {
            res = res * a;
        }
        a = a * a;
    }

    cout << res[1][0] << endl;
}