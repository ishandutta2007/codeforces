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
typedef double LD;
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

int nd[3];
int rd[3];
int dd[2];

LD range[3];

LD dp[22][22];

int cFreeze[11];
int nPositions;

LD result;

void go() {
    vector<pair<LD, LD> > damageModifiers;
    damageModifiers.PB(MP(-1e7, 1e7));
    for (int i = 0; i < nPositions; ++i) {
        for (int j = 0; j < cFreeze[i]; ++j) {
            damageModifiers.PB(MP(i - range[2], i + range[2]));
        }
    }
    for (int i = 0; i <= nd[0]; ++i) {
        for (int j = 0; j <= nd[1]; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < nPositions; ++i) {
        for (int k = 0; k < 2 - cFreeze[i]; ++k) {
            LD v0 = 0;
            LD v1 = 0;
            FORE (it, damageModifiers) {
                {
                    LD l = max(i - range[0], it->ST);
                    LD r = min(i + range[0], it->ND);
                    if (r > l) {
                        v0 += r - l;
                    }
                }
                {
                    LD l = max(i - range[1], it->ST);
                    LD r = min(i + range[1], it->ND);
                    if (r > l) {
                        v1 += r - l;
                    }
                }
            }
            v0 *= dd[0];
            v1 *= dd[1];
            for (int c0 = nd[0]; c0 >= 0; --c0) {
                for (int c1 = nd[1]; c1 >= 0; --c1) {
                    if (c0 > 0 && dp[c0 - 1][c1] > -0.5) {
                        dp[c0][c1] = max(dp[c0][c1], dp[c0 - 1][c1] + v0);
                    }
                    if (c1 > 0 && dp[c0][c1 - 1] > -0.5) {
                        dp[c0][c1] = max(dp[c0][c1], dp[c0][c1 - 1] + v1);
                    }
                }
            }
        }
    }
    result = max(result, dp[nd[0]][nd[1]]);
}

void dfs(int pos, int rem) {
    if (pos == nPositions) {
        if (rem == 0) {
            go();
        }
        return;
    }
    for (int i = 0; i <= 2 && i <= rem; ++i) {
        cFreeze[pos] = i;
        dfs(pos + 1, rem - i);
    }
}

int main() {
    scanf("%d %d %d", &nd[0], &nd[1], &nd[2]);
    scanf("%d %d %d", &rd[0], &rd[1], &rd[2]);
    scanf("%d %d", &dd[0], &dd[1]);
    result = 0;
    int n = nd[0] + nd[1] + nd[2];
    nPositions = (n + 1) / 2;
    for (int i = 0; i < 3; ++i) {
        // x^2 + 1^2 == r^2
        range[i] = sqrt(rd[i] * rd[i] - 1);
    }
    dfs(0, nd[2]);

    printf("%.9lf\n", result);
}