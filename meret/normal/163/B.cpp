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

typedef long double LD;

struct Lemming {
    int weight;
    int speed;
    int num;
};

bool operator < (const Lemming& a, const Lemming& b) {
    if (a.weight != b.weight) {
        return a.weight < b.weight;
    }
    return a.speed < b.speed;
}

int n, k;
Lemming lemmings[100005];
int picked[100005];

bool assign(LD maxTime) {
    int lastFree = 1;
    for (int i = 1; i <= n && lastFree <= k; ++i) {
        if (lastFree <= maxTime * (LD) lemmings[i].speed) {
            picked[lastFree++] = lemmings[i].num;
        }
    }
    return lastFree > k;
}

int main() {
    scanf("%d %d %*d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        lemmings[i].num = i;
        scanf("%d", &lemmings[i].weight);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &lemmings[i].speed);
    }
    sort(lemmings + 1, lemmings + n + 1);
    LD l = 0, r = 1e5 + 1;
    for (int it = 0; it < 100; ++it) {
        LD c = (l + r) / 2.0;
        if (assign(c)) {
            r = c;
        } else {
            l = c;
        }
    }
    assign(r);
    for (int i = 1; i <= k; ++i) {
        printf("%d", picked[i]);
        if (i < k) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}