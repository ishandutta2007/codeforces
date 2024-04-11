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

map<string, int>  val;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        int score;
        cin >> a >> score;
        val[a] = max(val[a], score);
    }
    n = val.size();
    cout << n << "\n";
    FORE (it, val) {
        int nNotWorse = 0;
        FORE (jt, val) {
            if (jt->ND <= it->ND) {
                ++nNotWorse;
            }
        }
        cout << it->ST << " ";
        if (nNotWorse * 100 >= n * 99) {
            cout << "pro\n";
        } else if (nNotWorse * 100 >= n * 90) {
            cout << "hardcore\n";
        } else if (nNotWorse * 100 >= n * 80) {
            cout << "average\n";
        } else if (nNotWorse * 100 >= n * 50) {
            cout << "random\n";
        } else {
            cout << "noob\n";
        }
    }
}