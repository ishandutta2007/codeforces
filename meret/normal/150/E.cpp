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
#define FORE(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 100005;

int n, minLen, maxLen;

int neededBeauty;

struct Edge {
    int dest;
    int beauty;

    Edge(int _dest = 0, int _beauty = 0) :
            dest(_dest), beauty(_beauty) {
    }
};

inline int ls(int x) {
    return x << 1;
}
inline int rs(int x) {
    return (x << 1) + 1;
}

const int INF = (int) 1e9;

int maxVal[4 * N];
int choice[4 * N];
int z;

int lastChosenU, lastChosenV;

void trackerAdd(int x, int l, int r, int c, int val, int pick) {
    if (l == r) {
        if (val > maxVal[x]) {
            maxVal[x] = val;
            choice[x] = pick;
        }
        return;
    }
    int m = (l + r) / 2;
    if (c <= m) {
        trackerAdd(ls(x), l, m, c, val, pick);
    } else {
        trackerAdd(rs(x), m + 1, r, c, val, pick);
    }
    if (maxVal[ls(x)] >= maxVal[rs(x)]) {
        maxVal[x] = maxVal[ls(x)];
        choice[x] = choice[ls(x)];
    } else {
        maxVal[x] = maxVal[rs(x)];
        choice[x] = choice[rs(x)];
    }
}

int trackerGet(int x, int l, int r, int cl, int cr) {
    if (l == cl && r == cr) {
        lastChosenU = choice[x];
        return maxVal[x];
    }
    int m = (l + r) / 2;
    int res = -INF;
    int myPick = -1;
    if (cl <= m) {
        int cur = trackerGet(ls(x), l, m, cl, min(m, cr));
        if (cur > res) {
            res = cur;
            myPick = lastChosenU;
        }
    }
    if (cr > m) {
        int cur = trackerGet(rs(x), m + 1, r, max(m + 1, cl), cr);
        if (cur > res) {
            res = cur;
            myPick = lastChosenU;
        }
    }
    lastChosenU = myPick;
    return res;
}

void prepareTracker(int total) {
    z = 1;
    while (z < total) {
        z *= 2;
    }
    for (int i = 1; i < z + z; ++i) {
        choice[i] = -1;
        maxVal[i] = -INF;
    }
}

void addVal(int pos, int val, int pick) {
    trackerAdd(1, 1, z, pos + 1, val, pick);
}

int getMax(int minPos, int maxPos) {
    ++minPos;
    ++maxPos;
    minPos = max(minPos, 1);
    maxPos = min(maxPos, z);
    if (minPos > maxPos) {
        return -INF;
    }
    return trackerGet(1, 1, z, minPos, maxPos);
}

vector<Edge> e[N];

bool considered[N];

int subtreeSize[N];

void computeSubtreeSize(int x) {
    subtreeSize[x] = 1;
    considered[x] = true;
    FORE (it, e[x]) {
        if (!considered[it->dest]) {
            computeSubtreeSize(it->dest);
            subtreeSize[x] += subtreeSize[it->dest];
        }
    }
    considered[x] = false;
}

vector<PII> permutation;

int findCenter(int x, int total) {
    considered[x] = true;
    bool goodCenter = ((total - subtreeSize[x]) * 2 <= total);
    FORE (it, e[x]) {
        if (!considered[it->dest]) {
            goodCenter &= (subtreeSize[it->dest] * 2 <= total);
        }
    }
    if (goodCenter) {
        return x;
    }
    FORE (it, e[x]) {
        if (!considered[it->dest]) {
            int cur = findCenter(it->dest, total);
            if (cur != -1) {
                considered[x] = false;
                return cur;
            }
        }
    }
    considered[x] = false;
    return -1;
}

vector<vector<pair<int, PII> > > subtrees[N];

void genSubtree(int x, int len, vector<pair<int, PII> >& res) {
    considered[x] = true;
    FORE (it, e[x]) {
        if (!considered[it->dest]) {
            res.PB(MP(it->dest, MP(x, it->beauty)));
            genSubtree(it->dest, len + 1, res);
        }
    }
    considered[x] = false;
}

int clen[N], csum[N];

bool considerPassing(int root, int total) {
    considered[root] = true;
    prepareTracker(total);
    addVal(0, 0, root);
    clen[root] = csum[root] = 0;
    FORE (v, subtrees[root]) {
        FORE (it, *v) {
            clen[it->ST] = clen[it->ND.ST] + 1;
            csum[it->ST] = csum[it->ND.ST] + ((it->ND.ND >= neededBeauty) ? 1 : -1);
        }
        FORE (it, *v) {
            int curMinLen = max(0, minLen - clen[it->ST]);
            int curMaxLen = maxLen - clen[it->ST];
            if (csum[it->ST] + getMax(curMinLen, curMaxLen) >= 0) {
                lastChosenV = it->ST;
                return true;
            }
        }
        FORE (it, *v) {
            addVal(clen[it->ST], csum[it->ST], it->ST);
        }
    }
    return false;
}

void genPermutation(int root) {
    computeSubtreeSize(root);
    int total = subtreeSize[root];
    root = findCenter(root, total);
    permutation.PB(MP(root, total));
    considered[root] = true;
    FORE (it, e[root]) {
        if (!considered[it->dest]) {
            vector<pair<int, PII> > cur;
            cur.PB(MP(it->dest, MP(root, it->beauty)));
            genSubtree(it->dest, 1, cur);
            subtrees[root].PB(cur);
            genPermutation(it->dest);
        }
    }
}

bool go() {
    for (int i = 1; i <= n; ++i) {
        considered[i] = false;
    }
    FORE (it, permutation) {
        if (considerPassing(it->ST, it->ND)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> beauties;
    scanf("%d %d %d", &n, &minLen, &maxLen);
    for (int i = 1; i <= n - 1; ++i) {
        int a, b, beauty;
        scanf("%d %d %d", &a, &b, &beauty);
        e[a].PB(Edge(b, beauty));
        e[b].PB(Edge(a, beauty));
        beauties.PB(beauty);
    }
    genPermutation(1);
    sort(ALL(beauties));
    beauties.erase(unique(ALL(beauties)), beauties.end());
    int l = 0, r = (int) beauties.size() - 1;
    while (l < r) {
        int c = (l + r + 1) / 2;
        neededBeauty = beauties[c];
        if (go()) {
            l = c;
        } else {
            r = c - 1;
        }
    }
    neededBeauty = beauties[l];
    go();
    printf("%d %d\n", lastChosenU, lastChosenV);
}