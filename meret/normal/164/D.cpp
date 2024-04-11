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

const int N = 1005;

int n, k;

bool e[N][N];
int deg[N];

bool removed[N];

vector<int> atDegree[4];

vector<int> neighbors[N];

void remove(int x) {
    assert(!removed[x]);
    deg[x] = (int) -1e9;
    removed[x] = true;
    FORE (it, neighbors[x]) {
        if (!removed[*it]) {
            --deg[*it];
            if (deg[*it] == 2) {
                atDegree[2].PB(*it);
            } else if (deg[*it] == 1) {
                atDegree[1].PB(*it);
            }
        }
    }
}

void unremove(int x) {
    assert(removed[x]);
    deg[x] = 0;
    removed[x] = false;
    FORE (it, neighbors[x]) {
        if (!removed[*it]) {
            ++deg[x];
            ++deg[*it];
            if (deg[*it] == 3) {
                atDegree[3].PB(*it);
            } else if (deg[*it] == 2) {
                atDegree[2].PB(*it);
            } else if (deg[*it] == 1) {
                atDegree[1].PB(*it);
            }
        }
    }
    if (deg[x] >= 3) {
        atDegree[3].PB(x);
    } else if (deg[x] == 2) {
        atDegree[2].PB(x);
    } else if (deg[x] == 1) {
        atDegree[1].PB(x);
    }
}

bool go(int rem) {
    if (rem < 0) {
        return false;
    }
    while (!atDegree[1].empty() && deg[atDegree[1].back()] != 1) {
        atDegree[1].pop_back();
    }
    while (!atDegree[2].empty() && deg[atDegree[2].back()] != 2) {
        atDegree[2].pop_back();
    }
    while (!atDegree[3].empty() && deg[atDegree[3].back()] < 3) {
        atDegree[3].pop_back();
    }
    if (!atDegree[1].empty()) {
        int u = atDegree[1].back();
        int v = -1;
        FORE (it, neighbors[u]) {
            if (!removed[*it]) {
                assert(v == -1);
                v = *it;
            }
        }
        assert(v != -1);
        if (rem >= 1) {
            remove(v);
            if (go(rem - 1)) {
                return true;
            }
            unremove(v);
        }
    } else if (!atDegree[3].empty()) {
        int u = atDegree[3].back();
        vector<int> v;
        FORE (it, neighbors[u]) {
            if (!removed[*it]) {
                v.PB(*it);
            }
        }
        assert((int) v.size() >= 3);
        if (rem >= 1) {
            remove(u);
            if (go(rem - 1)) {
                return true;
            }
            unremove(u);
        }
        if ((int) v.size() > rem) {
            return false;
        }
        FORE (it, v) {
            remove(*it);
        }
        if (go(rem - (int) v.size())) {
            return true;
        }
        FORE (it, v) {
            unremove(*it);
        }
    } else if (!atDegree[2].empty()) {
        int u = atDegree[2].back();
        int v = -1, w = -1;
        FORE (it, neighbors[u]) {
            if (!removed[*it]) {
                if (v != -1) {
                    assert(w == -1);
                    w = *it;
                } else {
                    v = *it;
                }
            }
        }
        assert(w != -1);
        vector<int> oth;
        FORE (it, neighbors[v]) {
            if (!removed[*it]) {
                oth.PB(*it);
            }
        }
        FORE (it, neighbors[w]) {
            if (!removed[*it]) {
                oth.PB(*it);
            }
        }
        sort(ALL(oth));
        oth.erase(unique(ALL(oth)), oth.end());
        if ((int) oth.size() <= rem) {
            FORE (it, oth) {
                remove(*it);
            }
            if (go(rem - (int) oth.size())) {
                return true;
            }
            FORE (it, oth) {
                unremove(*it);
            }
        }
        if (rem >= 2) {
            remove(v);
            remove(w);
            if (go(rem - 2)) {
                return true;
            }
            unremove(v);
            unremove(w);
        }
    } else {
        return true;
    }
    return false;
}

bool solve() {
    ZERO(removed);
    int rem = k;
    for (int i = 1; i <= n; ++i) {
        int cdeg = 0;
        for (int j = 1; j <= n; ++j) {
            cdeg += e[i][j];
        }
        if (cdeg > k) {
            --rem;
            removed[i] = true;
        }
    }
    if (rem < 0) {
        return false;
    }
    for (int i = 1; i <= n; ++i) {
        neighbors[i].clear();
    }
    int nEdges = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!removed[i] && !removed[j] && e[i][j]) {
                neighbors[i].PB(j);
                ++nEdges;
            }
        }
        deg[i] = neighbors[i].size();
    }
    if (nEdges > 2 * k * k) {
        return false;
    }
    for (int i = 1; i <= 3; ++i) {
        atDegree[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        if (!removed[i]) {
            if (deg[i] >= 3) {
                atDegree[3].PB(i);
            } else if (deg[i] >= 1) {
                atDegree[deg[i]].PB(i);
            }
        }
    }
    return go(rem);
}

LL dist[N][N];

void prep(LL c) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            e[i][j] = (dist[i][j] > c);
        }
    }
}

PII points[N];

LL sq(int x) {
    return x * (LL) x;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &points[i].ST, &points[i].ND);
    }
    LL md = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = sq(points[i].ST - points[j].ST) + sq(points[i].ND - points[j].ND);
            md = max(md, dist[i][j]);
        }
    }
    LL l = 0, r = md;
    while (l < r) {
        LL c = (l + r) / 2;
        prep(c);
        if (solve()) {
            r = c;
        } else {
            l = c + 1;
        }
    }
    prep(l);
    solve();
    int nRemoved = 0;
    for (int i = 1; i <= n; ++i) {
        nRemoved += removed[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!removed[i] && nRemoved < k) {
            ++nRemoved;
            removed[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (removed[i]) {
            printf("%d", i);
            if (--nRemoved > 0) {
                printf(" ");
            }
        }
    }
    printf("\n");
}