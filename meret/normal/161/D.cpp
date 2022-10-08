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

const int N = 200005;

vector<int> e[N];

bool considered[N];

int subtreeSize[N];

int atDist[N];

int k;

void prepareTracker(int total) {
    for (int i = 0; i <= total; ++i) {
        atDist[i] = 0;
        if (i <= k) {
            atDist[k - i] = 0;
        }
    }
}

void computeSubtreeSize(int x) {
    subtreeSize[x] = 1;
    considered[x] = true;
    FORE (it, e[x]) {
        if (!considered[*it]) {
            computeSubtreeSize(*it);
            subtreeSize[x] += subtreeSize[*it];
        }
    }
    considered[x] = false;
}

int findCenter(int x, int total) {
    considered[x] = true;
    bool goodCenter = ((total - subtreeSize[x]) * 2 <= total);
    FORE (it, e[x]) {
        if (!considered[*it]) {
            goodCenter &= (subtreeSize[*it] * 2 <= total);
        }
    }
    if (goodCenter) {
        return x;
    }
    FORE (it, e[x]) {
        if (!considered[*it]) {
            int cur = findCenter(*it, total);
            if (cur != -1) {
                considered[x] = false;
                return cur;
            }
        }
    }
    considered[x] = false;
    return -1;
}

LL result;

void processSubtree(int x, int dst) {
    considered[x] = true;
    {
        if (dst <= k) {
            result += atDist[k - dst];
        }
    }
    FORE (it, e[x]) {
        if (!considered[*it]) {
            processSubtree(*it, dst + 1);
        }
    }
    considered[x] = false;
}

void addSubtree(int x, int dst) {
    considered[x] = true;
    ++atDist[dst];
    FORE (it, e[x]) {
        if (!considered[*it]) {
            addSubtree(*it, dst + 1);
        }
    }
    considered[x] = false;
}

bool considerPassing(int root, int total) {
    considered[root] = true;
    prepareTracker(total);
    ++atDist[0];
    FORE (it, e[root]) {
        if (!considered[*it]) {
            processSubtree(*it, 1);
            addSubtree(*it, 1);
        }
    }
    return false;
}

bool solve(int root) {
    computeSubtreeSize(root);
    int total = subtreeSize[root];
    root = findCenter(root, total);
    if (considerPassing(root, total)) {
        return true;
    }
    FORE (it, e[root]) {
        if (!considered[*it]) {
            if (solve(*it)) {
                return true;
            }
        }
    }
    return false;
}

int n;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].PB(b);
        e[b].PB(a);
    }
    result = 0;
    solve(1);
    cout << result << "\n";
}