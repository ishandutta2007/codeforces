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

const int A = 500;

int t[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    t[A][A] = n;
    int sz = 0;
    while (true) {
        bool ok = false;
        for (int x = A - sz; x <= A + sz; ++x) {
            for (int y = A - sz; y <= A + sz; ++y) {
                if (t[x][y] >= 4) {
                    if (max(abs(x - A), abs(y - A)) == sz) {
                        ++sz;
                    }
                    ok = true;
                    t[x - 1][y] += t[x][y] / 4;
                    t[x + 1][y] += t[x][y] / 4;
                    t[x][y - 1] += t[x][y] / 4;
                    t[x][y + 1] += t[x][y] / 4;
                    t[x][y] %= 4;
                }
            }
        }
        if (!ok) {
            break;
        }
    }
    int d;
    cin >> d;
    while (d--) {
        int x, y;
        cin >> x >> y;
        if (max(abs(x), abs(y)) > sz) {
            cout << 0 << "\n";
        } else {
            cout << t[A + x][A + y  ] << "\n";
        }
    }
}