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

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, vector<PII> > cubes;
    map<int, LL> sums;
    map<int, int> bestColor;

    for (int i = 1; i <= n; ++i) {
        int color, size;
        cin >> color >> size;
        cubes[color].PB(MP(size, i));
        sums[color] += size;
    }

    FORE (it, cubes) {
        sort(ALL(it->ND));
        reverse(ALL(it->ND));
    }

    FORE (it, sums) {
        int mySize = cubes[it->ST].size();
        if (bestColor.find(mySize) == bestColor.end() || sums[bestColor[mySize]] < it->ND) {
            bestColor[mySize] = it->ST;
        }
    }

    int col1, col2;
    LL score = -1;

    FORE (it, cubes) {
        LL sum = 0;
        for (int used = 1; used <= (int) it->ND.size(); ++used) {
            sum += it->ND[used - 1].ST;
            if (used == 1) {
                if (sum > score) {
                    score = sum;
                    col1 = it->ST;
                    col2 = -1;
                }
            } else {
                if (bestColor.find(used - 1) != bestColor.end() && sums[bestColor[used - 1]] + sum > score) {
                    score = sums[bestColor[used - 1]] + sum;
                    col1 = it->ST;
                    col2 = bestColor[used - 1];
                }
            }
            if (bestColor.find(used) != bestColor.end() && bestColor[used] != it->ST && sums[bestColor[used]] + sum > score) {
                score = sums[bestColor[used]] + sum;
                col1 = it->ST;
                col2 = bestColor[used];
            }
        }
    }

    cout << score << "\n";
    cout << cubes[col2].size() + min(cubes[col2].size() + 1, cubes[col1].size()) << "\n";

    int i = 0;

    while (i < (int) cubes[col2].size()) {
        cout << cubes[col1][i].ND << " ";
        cout << cubes[col2][i++].ND << " ";
    }
    if (i < (int) cubes[col1].size()) {
        cout << cubes[col1][i++].ND << " ";
    }
    cout << "\n";
}