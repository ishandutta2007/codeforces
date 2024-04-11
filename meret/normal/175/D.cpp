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

struct Tank {
    int hp;
    int dt;
    int l, r;
    int p;

    double chanceDestroys[21];

    vector<double> options;

    void calc(const Tank& other) {
        static double dp[21][205];
        ZERO(dp);
        ZERO(chanceDestroys);
        dp[0][other.hp] = 1;
        for (int i = 1; i <= 20; ++i) {
            for (int prev = 0; prev <= other.hp; ++prev) {
                if (prev == 0) {
                    dp[i][prev] += dp[i - 1][prev];
                } else {
                    for (int j = l; j <= r; ++j) {
                        int next = max(prev - j, 0);
                        double ch = dp[i - 1][prev] / (double) (r - l + 1);
                        if (next == 0) {
                            chanceDestroys[i] += ch;
                        }
                        dp[i][next] += ch;
                    }
                }
            }
        }


        static double ch[21];
        ZERO(ch);
        ch[0] = 1;
        options.resize(100000 + 1, 0);
        for (int i = 1; i <= 100000; ++i) {
            double cur = 0;
            for (int j = 20; j >= 0; --j) {
                cur += (ch[j - 1] * (100 - p) / 100.0) * chanceDestroys[j];
                ch[j] = (ch[j] * p + ch[j - 1] * (100 - p)) / 100.0;
            }
            options[i] = cur;
        }
    }

    void read() {
        scanf("%d %d %d %d %d", &hp, &dt, &l, &r, &p);
    }
};

Tank a, b;

int main() {
    a.read();
    b.read();
    a.calc(b);
    b.calc(a);
    if (a.p == 100) {
        printf("%.9lf\n", 0.0);
        return 0;
    } else if (b.p == 100) {
        printf("%.9lf\n", 1.0);
        return 0;
    }
    double result = 0;
    for (int i = 1; i <= 100000; ++i) {
        a.options[i] += a.options[i - 1];
    }
    for (int i = 1; i <= 100000; ++i) {
        int myShots = (b.dt * (i - 1)) / a.dt + 1;
        if (myShots > 0 && myShots <= 100000) {
            result += b.options[i] * a.options[myShots];
        }
    }
    printf("%.9lf\n", result);
}