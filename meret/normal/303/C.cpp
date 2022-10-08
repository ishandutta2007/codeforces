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
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<int> df[1000005];

bool taken[1000005];
bool used[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i <= 1000000; ++i) {
        df[i].reserve(10);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j) {
                int c = abs(v[i] - v[j]);
                if ((int) df[c].size() < 2 * (k + 1)) {
                    df[c].PB(v[i]);
                    df[c].PB(v[j]);
                }
            }
        }
    }
    for (int m = 1; m <= 1000001; ++m) {
        vector<int> cused;
        int res = 0;
        for (int d = 0; d <= 1000000; d += m) {
            if ((int) df[d].size() >= 2 * (k + 1)) {
                res = k + 1;
                break;
            }
            FORE (it, df[d]) {
                if (used[*it]) {
                    continue;
                }
                int a = *it % m;
                if (taken[a]) {
                    ++res;
                } else {
                    taken[a] = true;
                }
                used[*it] = true;
                cused.PB(*it);
            }
            if (res > k) {
                break;
            }
        }
        if (res <= k) {
            cout << m << endl;
            return 0;
        }
        FORE (it, cused) {
            used[*it] = false;
            taken[*it % m] = false;
        }
    }
}