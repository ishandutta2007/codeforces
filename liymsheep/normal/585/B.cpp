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

char buf[1000];
bool dp[3][501];

int dy[3] = {-1, 0, 1};

vector< pair<int, PII> > trains;

bool good(int i, int j, int t) {
    TR(it, trains) {
        if (it->first != j) {
            continue;
        }
        int l = it->second.first;
        int r = it->second.second;

        if (l - 2 * t <= i && r - 2 * t >= i) {
            return false;
        }
        if (l - 2 * t > i) {
            if (l - (2 * (t + 1)) <= i) {
                return false;
            }
        }
    }
    return true;
}

bool good2(int i, int j, int t) {
    TR(it, trains) {
        if (it->first != j) {
            continue;
        }
        int l = it->second.first;
        int r = it->second.second;

        if (l - 2 * t <= i && r - 2 * t >= i) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int sx, sy;
    trains.clear();
    REP(r, 3) {
        scanf("%s", buf);
        for (int i = 0; i < n; ++i) {
            if (buf[i] == '.') continue;
            if (buf[i] == 's') {
                sx = r; sy = i;
                continue;
            }
            int j = i;
            while (j < n && buf[i] == buf[j]) {
                ++j;
            }
            trains.PB(MP(r, MP(i, j - 1)));
            i = j - 1;
        }
    }

    // cout << good(2, 0, 1) << endl;
    CLEAR(dp);
    dp[sx][sy] = true;
    for (int t = 0; t <= n + 2; ++t) {
        int i = sy + t;
        for (int j = 0; j < 3; ++j) {
            if (dp[j][i]) {
                int ni = i + 1;
                for (int d = 0; d < 3; ++d) {
                    int nj = j + dy[d];
                    if (nj < 0 || nj > 2) continue;
                    if (good2(ni, j, t) && good(ni, nj, t)) {
                        // cout << "(ni, nj) = " <<  ni << ", " << nj << endl;
                        dp[nj][ni] = true;
                    }
                }
            }
        }
    }

    bool ans = dp[0][n] || dp[1][n] || dp[2][n];
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}