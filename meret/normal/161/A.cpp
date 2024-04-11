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

int n, m, x, y;

PII sol[200005];
PII vests[200005];
int l = 0;

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sol[i].ST);
        sol[i].ND = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &vests[i].ST);
        vests[i].ND = i + 1;
    }
    sort(sol, sol + n);
    sort(vests, vests + m);
    int l = 0;
    vector<PII> v;
    for (int i = 0; i < n; ++i) {
        while (l < m && vests[l].ST < sol[i].ST - x) {
            ++l;
        }
        if (l < m && vests[l].ST <= sol[i].ST + y) {
            v.PB(MP(sol[i].ND, vests[l].ND));
            ++l;
        }
    }
    printf("%d\n", (int) v.size());
    FORE (it, v) {
        printf("%d %d\n", it->ST, it->ND);
    }
}