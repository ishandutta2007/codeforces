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

const int MX = (int) 1e6 + 5;

int n, m;

vector<int> a, b;

int posA[MX], posB[MX];

bool good(int i, int j, int k) {
    if (k == -1) {
        return false;
    }
    if (j >= i) {
        return k > j || k < i;
    } else {
        return k > j && k < i;
    }
}

int length(int i, int j) {
    if (j >= i) {
        return j - i + 1;
    } else {
        return j - i + 1 + n;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    a.resize(n);
    b.resize(m);
    memset(posA, -1, sizeof(posA));
    memset(posB, -1, sizeof(posB));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        posA[a[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        posB[b[i]] = i;
    }
    int result = 0;
    int r = -1;
    for (int l = 0; l < n; ++l) {
        if (r == -1 && posB[a[l]] != -1) {
            r = l;
        }
        if (r != -1) {
            int startB = posB[a[l]];
            while ((r + 1) % n != l && good(posB[a[l]], posB[a[r]], posB[a[(r + 1) % n]])) {
                r = (r + 1) % n;
            }
            result = max(result, length(l, r));
            if (l == r) {
                r = -1;
            }
        }
    }
    printf("%d\n", result);
}