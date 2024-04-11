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

bool taken[40005];

int val[] = {
        0,
        1,
        2,
        1,
        4,
        3,
        2,
        1,
        5,
        6,
        2,
        1,
        8,
        7,
        5,
        9,
        8,
        7,
        3,
        4,
        7,
        4,
        2,
        1,
        10,
        9,
        3,
        6,
        11,
        12
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    int rem = n;
    for (int i = 2; i * i <= n; ++i) {
        if (taken[i]) {
            continue;
        }
        int sz = 1;
        int a = i;
        taken[a] = true;
        while (a * (LL) i <= n) {
            a *= i;
            ++sz;
            if (a * (LL) a <= n) {
                taken[a] = true;
            }
        }
        rem -= sz;
        res ^= val[sz];
    }
    res ^= (rem % 2);
    cout << (res ? "Vasya" : "Petya") << endl;
}