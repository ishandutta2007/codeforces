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
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<int> primes;
int np;

bool isPrime(int x) {
    if (x <= 2) {
        return x == 2;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int intLen(int x) {
    int res = 1;
    while (x >= 10) {
        ++res;
        x /= 10;
    }
    return res;
}

const int MX = 100000;

int le[6][6][100005];
int ri[6][6][100005];

int dig[6];

int n;
int result;

void go(int x) {
    if (x == n) {
        ++result;
        return;
    }
    int pref = dig[x];
    for (int i = le[n][x][pref]; i <= ri[n][x][pref]; ++i) {
        int cur = primes[i];
        bool bad = false;
        for (int j = n - 1; j > x; --j) {
            dig[j] = dig[j] * 10 + cur % 10;
            if (le[n][x + 1][dig[j]] > ri[n][x + 1][dig[j]]) {
                bad = true;
            }
            cur /= 10;
        }
        if (!bad) {
            go(x + 1);
        }
        for (int j = n - 1; j > x; --j) {
            dig[j] /= 10;
        }
    }
}

int main() {
    for (int i = 2; i < MX; ++i) {
        if (isPrime(i)) {
            primes.PB(i);
        }
    }
    np = primes.size();
    for (int len = 0; len <= 5; ++len) {
        for (int j = 0; j <= len; ++j) {
            for (int i = 0; i < MX; ++i) {
                le[len][j][i] = np;
                ri[len][j][i] = -1;
            }
        }
    }
    for (int i = 0; i < np; ++i) {
        int cur = primes[i];
        int myLen = intLen(cur);
        for (int len = myLen; len <= 5; ++len) {
            int p10 = 1;
            for (int j = 0; j <= len; ++j) {
                le[len][len - j][cur / p10] = min(le[len][len - j][cur / p10], i);
                ri[len][len - j][cur / p10] = max(ri[len][len - j][cur / p10], i);
                p10 *= 10;
            }
        }
    }
    int d;
    scanf("%d", &d);
    while (d--) {
        int a;
        scanf("%d", &a);
        n = intLen(a);

        for (int i = n - 1; i > 0; --i) {
            dig[i] = a % 10;
            a /= 10;
        }

        result = 0;
        go(1);

        printf("%d\n", result);
    }
}