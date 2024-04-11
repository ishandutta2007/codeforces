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

int c[4];
int r[4];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < 2 * n; ++i) {
        int a = 2 * (int) (s[i] - '0') + (int) (t[i] - '0');
        ++c[a];
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2 == 0) {
            if (c[3]) {
                --c[3];
                ++r[0];
            } else if (c[2]) {
                --c[2];
                ++r[0];
            } else if (c[1]) {
                --c[1];
            }
        } else {
            if (c[3]) {
                --c[3];
                ++r[1];
            } else if (c[1]) {
                --c[1];
                ++r[1];
            } else if (c[2]) {
                --c[2];
            }
        }
    }
    if (r[0] == r[1]) {
        cout << "Draw\n";
    } else if (r[0] > r[1]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}