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
#define FOR(v,p,k) for(int v=p;v<k;++v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int MD = (int)1e9 + 7;

LL mul(LL a, LL b) {
    return (a * b) % MD;
}

LL pot(LL a, LL b) {
    LL res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
    }
    return res;
}

LL inv(LL x) {
    return pot(x, MD - 2);
}

int main() {
    int k;
    cin >> k;
    bool even_n = true;
    LL q = 2;
    while (k--) {
        LL a;
        cin >> a;
        q = pot(q, a);
        if (a % 2 == 0) {
            even_n = false;
        }
    }
    q = mul(q, inv(2));
    LL p;
    if (even_n) {
        p = (q - 1) % MD;
    } else {
        p = (q + 1) % MD;
    }
    p = mul(p, inv(3));
    cout << p << "/" << q << endl;
}