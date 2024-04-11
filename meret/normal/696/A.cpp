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
#define FOR(v,p,k) for(int v=p;v<k;++v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<LL> get_path(LL u, LL v) {
    vector<LL> result;
    while (u != v) {
        if (u > v) {
            result.PB(u);
            u >>= 1;
        } else {
            result.PB(v);
            v >>= 1;
        }
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    map<LL, LL> cost;
    while (q--) {
        int q_type;
        cin >> q_type;
        LL u, v;
        cin >> u >> v;
        vector<LL> path = get_path(u, v);
        if (q_type == 1) {
            LL w;
            cin >> w;
            FORE (it, path) {
                cost[*it] += w;
            }
        } else {
            LL res = 0;
            FORE (it, path) {
                res += cost[*it];
            }
            cout << res << endl;
        }
    }
}