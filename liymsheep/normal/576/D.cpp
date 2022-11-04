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

using namespace std;

const double eps = 1e-12;

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

typedef bitset<150> vec;

vec now, vmat[150], tmp[150], tmp2[150], a[150];

void mul(vec* ret, vec* a, vec* b) {
    REP(i, 150) REP(j, 150) vmat[j][i] = b[i][j];
    REP(i, 150) REP(j, 150) tmp2[i][j] = (a[i] & vmat[j]).any();
    REP(i, 150) ret[i] = tmp2[i];
}

vec mul(vec a, vec* b) {
    vec result;
    REP(i, 150) if (a[i]) {
        REP(j, 150) if (b[i][j]) {
            result[j] = true;
        }
    }
    return result;
}

void power(vec* ret, vec* v, LL p) {
    REP(i, 150) {
        a[i] = v[i];
        tmp[i].reset();
        tmp[i][i] = true;
    }
    for (; p; p >>= 1LL) {
        if (p & 1LL) {
            mul(tmp, tmp, a);
        }
        mul(a, a, a);
    }
    REP(i, 150) {
        ret[i] = tmp[i];
    }
}

vec conn[150];

int main() {
    int n, m;
    cin >> n >> m;
    vector< pair<int, PII> > edges;
    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.PB(MP(w, MP(u, v)));
    }
    SORT(edges);
    now.reset();
    now[0] = true;
    if (edges[0].first != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[i].first == edges[j].first) {
            ++j;
        }        REP(k, 150) {
            conn[k].reset();
        }
        REP(k, j) {
            conn[edges[k].second.first][edges[k].second.second] = true;
        }
        int steps = 155;
        if (j < m) {
            steps = min(steps, edges[j].first - edges[i].first);
        }
        vec current = now;
        REP(k, steps) {
            current = mul(current, conn);
            if (current[n - 1]) {
                cout << edges[i].first + k + 1 << endl;
                return 0;
            }
        }
        if (j == m) {
            cout << "Impossible" << endl;
            return 0;
        }
        // REP(x, n) { REP(y, n) cout << conn[x][y] << " "; cout << endl;}
        power(conn, conn, edges[j].first - edges[i].first);
        // cout << "==" << endl;
        // REP(x, n) { REP(y, n) cout << conn[x][y] << " "; cout << endl;}
        now = mul(now, conn);
        // REP(x, n) cout << now[x] << ", ";
        // cout << endl;
        i = j;
    }
    return 0;
}