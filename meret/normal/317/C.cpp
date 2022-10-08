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

int sk[305];

LL sum_sk[305];

bool is_path[305][305];
int nx[305][305];

int current[305];
int desired[305];

int n, volume, m;

vector<int> x;
vector<int> y;
vector<int> d;

void dom(int a, int b, int c) {
    x.PB(a);
    y.PB(b);
    d.PB(c);
    current[a] -= c;
    current[b] += c;
}

void move(vector<int>& v, int l, int r, int val) {
    if (l + 1 == r) {
        dom(v[l], v[r], val);
        return;
    }
    if (current[v[r - 1]] >= val) {
        dom(v[r - 1], v[r], val);
        move(v, l, r - 1, val);
    } else {
        dom(v[r - 1], v[r], current[v[r - 1]]);
        move(v, l, r - 1, val);
        dom(v[r - 1], v[r], val - desired[v[r - 1]]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> volume >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> current[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> desired[i];
    }
    for (int i = 1; i <= n; ++i) {
        is_path[i][i] = true;
    }
    memset(nx, -1, sizeof(nx));
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        is_path[x][y] = true;
        nx[x][y] = y;
        is_path[y][x] = true;
        nx[y][x] = x;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!is_path[i][j] && is_path[i][k] && is_path[k][j]) {
                    is_path[i][j] = true;
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        sk[i] = 1;
        while (!is_path[i][sk[i]]) {
            ++sk[i];
        }
        sum_sk[sk[i]] += current[i] - desired[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (sum_sk[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    while (true) {
        int l = 1;
        while (l <= n && current[l] <= desired[l]) {
            ++l;
        }
        if (l > n) {
            break;
        }
        int r = 1;
        while (!is_path[l][r] || current[r] >= desired[r]) {
            ++r;
        }
        vector<int> path;
        for (int c = l; c != -1; c = nx[c][r]) {
            path.PB(c);
        }
        for (int i = (int) path.size() - 1; ; --i) {
            if (current[path[i]] > desired[path[i]]) {
                l = i;
                break;
            }
        }
        for (int i = l; ; ++i) {
            if (current[path[i]] < desired[path[i]]) {
                r = i;
                break;
            }
        }
        int transferred = min(current[path[l]] - desired[path[l]], desired[path[r]] - current[path[r]]);
        move(path, l, r, transferred);
    }
    cout << x.size() << endl;
    for (int i = 0; i < (int) x.size(); ++i) {
        cout << x[i] << " " << y[i] << " " << d[i] << "\n";
    }
}