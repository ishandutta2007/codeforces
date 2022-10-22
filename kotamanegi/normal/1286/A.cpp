#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
const long double Ma_PI = 3.1415926535897932384626433832795028841971L;
#define eps 1e-7
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int dp[200][101][101][2] = {};
void solve() {
    int n;
    cin >> n;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    int cnt[2] = {};
    for (int i = 1; i <= n; ++i) {
        int ok = 1;
        REP(q, n) {
            if (inputs[q] == i) ok = 0;
        }
        cnt[i % 2] += ok;
    }
    REP(i, 200) {
        REP(q, 101) {
            REP(j, 101) {
                REP(t, 2) {
                    dp[i][q][j][t] = 1e9;
                }
            }
        }
    }
    dp[0][cnt[0]][cnt[1]][0] = 0;
    dp[0][cnt[0]][cnt[1]][1] = 0;
    for (int i = 0; i < n; ++i) {
        if (inputs[i] == 0) {
            //free
            REP(q, n+1) {
                REP(j, n + 1) {
                    REP(t, 2) {
                        if (dp[i][q][j][t] == 1e9) continue;
                        if(q > 0){
                            //take 0
                            int costs = dp[i][q][j][t];
                            if (t == 1) {
                                costs++;
                            }
                            dp[i + 1][q - 1][j][0] = min(dp[i + 1][q - 1][j][0], costs);
                        }
                        if(j > 0){
                            //take 1
                            int costs = dp[i][q][j][t];
                            if (t == 0) {
                                costs++;
                            }
                            dp[i + 1][q][j - 1][1] = min(dp[i + 1][q][j - 1][1], costs);
                        }
                    }
                }
            }
        }
        else {
            REP(q, n + 1) {
                REP(j, n + 1) {
                    REP(t, 2) {
                        if (dp[i][q][j][t] == 1e9) continue;
                        if (inputs[i] % 2 == 0) {
                            //take 0
                            int costs = dp[i][q][j][t];
                            if (t == 1) {
                                costs++;
                            }
                            dp[i + 1][q][j][0] = min(dp[i + 1][q][j][0], costs);
                        }
                        if (inputs[i] % 2 == 1) {
                            //take 1
                            int costs = dp[i][q][j][t];
                            if (t == 0) {
                                costs++;
                            }
                            dp[i + 1][q][j][1] = min(dp[i + 1][q][j][1], costs);
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[n][0][0][0],dp[n][0][0][1]) << endl;
    return;
}
int main() {
    init();
    solve();
}