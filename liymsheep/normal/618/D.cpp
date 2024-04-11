#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

const int N = 2000007;

VI edge[N];
int n;
set<PII> edges;

bool isCenter(int x) {
    REP(i, n) {
        if (i != x) {
            if (edges.find(MP(x, i)) == edges.end()) {
                return false;
            }
        }
    }
    return true;
}

int f[N], g[N];

void dp(int x, int fa) {
    bool leaf = true;
    f[x] = g[x] = 0;
    VI fs;
    TR(it, edge[x]) {
        if (*it == fa) {
            continue;
        }
        leaf = false;
        dp(*it, x);
        fs.PB(f[*it] - g[*it]);
        g[x] += g[*it];
        f[x] += g[*it];
    }

    SORT(fs);
    reverse(ALL(fs));

    int gSum = g[x];
    if (fs.size() >= 1) {
        f[x] = max(f[x], f[x] + fs[0] + 1);
        g[x] = max(g[x], f[x]);
    }
    if (fs.size() >= 2) {
        g[x] = max(g[x], gSum + fs[0] + fs[1] + 2);
    }
}

int main() {
    cin >> n;
    LL a, b;
    cin >> a >> b;
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        edge[u].PB(v);
        edge[v].PB(u);
        edges.insert(MP(u, v));
        edges.insert(MP(v, u));
    }

    if (a > b) {
        int x = 0;
        bool star = false;
        if (isCenter(x)) {
            star = true;
        } else {
            x = edge[x][0];
            if (isCenter(x)) {
                star = true;
            }
        }
        if (star) {
            cout << a + b * (n - 2) << endl;
        } else {
            cout << b * (n - 1) << endl;
        }
        return 0;
    }

    dp(0, -1);
    LL m = g[0];
    cout << m * a + (n - 1 - m) * b << endl;
    return 0;
}