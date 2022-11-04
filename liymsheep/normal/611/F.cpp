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

const int N = 1000007;
const int MODULO = 1000000007;

char op[N];
int when[4][N];

int main() {
    int n, m, len;
    cin >> len >> n >> m;
    scanf("%s", op);

    int x1 = 0, x2 = n - 1, y1 = 0, y2 = m - 1;
    LL ans = 0;

    VI u, l, d, r;
    FILL(when, -1);
    REP(i, len) {
        if (x1 > x2 || y1 > y2) break;

        if (op[i] == 'U') {
            if (x1 == 0) {
                ans += (i + 1) * (LL) (y2 - y1 + 1);
                ans %= MODULO;
                --x2;
                when[0][u.size()] = i;
                u.PB(i);
            } else {
                --x1;
                --x2;
            }
        } else if (op[i] == 'D') {
            if (x2 == n - 1) {
                ans += (i + 1) * (LL) (y2 - y1 + 1);
                ans %= MODULO;
                ++x1;
                when[1][d.size()] = i;
                d.PB(i);
            } else {
                ++x1;
                ++x2;
            }
        } else if (op[i] == 'L') {
            if (y1 == 0) {
                ans += (i + 1) * (LL) (x2 - x1 + 1);
                ans %= MODULO;
                --y2;
                when[2][l.size()] = i;
                l.PB(i);
            } else {
                --y1;
                --y2;
            }
        } else {
            // cout << "OP IS " << op[i] << endl;
            assert(op[i] == 'R');
            if (y2 == m - 1) {
                ans += (i + 1) * (LL) (x2 - x1 + 1);
                ans %= MODULO;
                ++y1;
                when[3][r.size()] = i;
                r.PB(i);
            } else {
                ++y1;
                ++y2;
            }
        }
    }

    // cout << "ans is " << ans << endl;
    // cout << "x1 is " << x1 << ", x2 is " << x2 << ", y1 is " << y1 << " y2 is " << y2 << endl;

    int dx = x1 - (int) (u.size());
    int dy = y1 - (int) (l.size());

    LL current = len;
    while (x1 <= x2 && y1 <= y2) {
        priority_queue<PII> pq;
        bool changed = false;
        while (x1 <= x2 && y1 <= y2) {
            int dir = -1, t;
            if (when[0][x1] >= 0 && (dir == -1 || when[0][x1] < t)) {
                dir = 0;
                t = when[0][x1];
            }
            if (when[1][n - 1 - x2] >= 0 && (dir == -1 || when[1][n - 1 - x2] < t)) {
                dir = 1;
                t = when[1][n - 1 - x2];
            }
            if (when[2][y1] >= 0 && (dir == -1 || when[2][y1] < t)) {
                dir = 2;
                t = when[2][y1];
            }
            if (when[3][m - 1 - y2] >= 0 && (dir == -1 || when[3][m - 1 - y2] < t)) {
                dir = 3;
                t = when[3][m - 1 - y2];
            }

            // cout << "y2 is " << y2 << ", " << "when is " << when[3][m] << endl;
            // cout << "dir is " << dir << endl;

            if (dir == -1) {
                break;
            }

            if (dir == 0) {
                ans += (t + 1 + current) * (LL) (y2 - y1 + 1);
                ans %= MODULO;
                ++x1;
            } else if (dir == 1) {
                ans += (t + 1 + current) * (LL) (y2 - y1 + 1);
                ans %= MODULO;
                --x2;
            } else if (dir == 2) {
                ans += (t + 1 + current) * (LL) (x2 - x1 + 1);
                ans %= MODULO;
                ++y1;
            } else {
                assert(dir == 3);
                ans += (t + 1 + current) * (LL) (x2 - x1 + 1);
                ans %= MODULO;
                --y2;
            }

            changed = true;
        }

        if (!changed || !(x1 <= x2 && y1 <= y2)) {
            break;
        }

        x1 += dx;
        x2 += dx;
        y1 += dy;
        y2 += dy;

        assert(x1 >= 0 && x1 < n);
        assert(x2 >= 0 && x2 < n);
        assert(y1 >= 0 && y1 < m);
        assert(y2 >= 0 && y2 < m);

        current += len;
        if (current >= MODULO) {
            current -= MODULO;
        }
    }

    if (x1 <= x2 && y1 <= y2) {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}