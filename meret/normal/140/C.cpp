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

map<int, int> cnt;

int n;

set<PII> s;

int main() {
    scanf("%d", &n);
    for (int i  = 0; i < n; ++i) {
        int r;
        scanf("%d", &r);
        ++cnt[r];
    }
    FORE (it, cnt) {
        s.insert(MP(-it->ND, it->ST));
    }
    vector<vector<int> > res;
    while (s.size() >= 3) {
        vector<int> v;
        PII p[3];
        for (int i = 0; i < 3; ++i) {
            p[i] = *s.begin();
            s.erase(s.begin());
        }
        for (int i = 0; i < 3; ++i) {
            v.PB(p[i].ND);
            if (p[i].ST < -1) {
                s.insert(MP(p[i].ST + 1, p[i].ND));
            }
        }
        sort(ALL(v));
        reverse(ALL(v));
        res.PB(v);
    }
    printf("%u\n", res.size());
    FORE (it, res) {
        printf("%d %d %d\n", (*it)[0], (*it)[1], (*it)[2]);
    }
}