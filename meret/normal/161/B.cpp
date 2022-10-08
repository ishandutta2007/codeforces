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

bool gotStool[1005];
vector<PII> inside[1005];
int stoolSize[1005];

vector<PII> stools;

vector<PII> other;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a, type;
        cin >> a >> type;
        if (type == 1) {
            stools.PB(MP(a, i));
        } else {
            other.PB(MP(a, i));
        }
    }
    sort(ALL(stools));
    reverse(ALL(stools));
    int withStools = min(k, (int) stools.size());
    for (int i = 0; i < withStools; ++i) {
        inside[i + 1].PB(stools[i]);
        stoolSize[i + 1] = stools[i].ST;
        gotStool[i + 1] = true;
    }
    for (int i = k; i < (int) stools.size(); ++i) {
        other.PB(stools[i]);
    }
    sort(ALL(other));
    reverse(ALL(other));
    for (int i = k; i > withStools; --i) {
        inside[i].PB(other.back());
        other.pop_back();
    }
    FORE (it, other) {
        inside[k].PB(*it);
    }
    LL result = 0;
    for (int i = 1; i <= k; ++i) {
        sort(ALL(inside[i]));
        FORE (it, inside[i]) {
            result += 2LL * it->ST;
        }
        if (gotStool[i]) {
            result -= inside[i][0].ST;
        }
    }
    cout << (result / 2) << "." << (5 * (result % 2)) << "\n";
    for (int i = 1; i <= k; ++i) {
        cout << inside[i].size();
        FORE (it, inside[i]) {
            cout << " " << it->ND;
        }
        cout << "\n";
    }
}