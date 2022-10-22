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
#define Ma_PI 3.141592653589793
#define eps 1e-5
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
#define int ll
int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int go[3000];
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> inputs;
    int s_a, s_b;
    cin >> s_a >> s_b;
    inputs.pb(mp(0, 0));
    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        inputs.push_back(mp(a - s_a, b - s_b));
    }
    while (true) {
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            long long a = inputs[i].first + (int)1e9;
            long long b = inputs[i].second + (int)1e9;
            if (a % 2 == 1||b % 2 == 1) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
        for (int i = 0; i < n; ++i) {
            long long a = inputs[i].first + (int)1e9;
            long long b = inputs[i].second + (int)1e9;
            inputs[i].first /= 2;
            inputs[i].second /= 2;
        }
    }
    REP(i, n) {
        if (((long long)1e9 + inputs[i].first) % 2LL == ((long long)1e9 + inputs[i].second) % 2LL) {
            go[i] = 1;
        }
    }
    int ok = 0;
    for (int i = 1; i < n; ++i) {
        if (go[i - 1] != go[i]) {
            ok = 1;
            break;
        }
    }
    if (ok == 1) {
        vector<int> ans;
        REP(i, n) {
            if (go[i]) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else {
        REP(i, n) {
            if (((long long)1e9 + inputs[i].first) % 2LL ==0) {
                go[i] = 1;
            }
            else {
                go[i] = 0;
            }
        }
        vector<int> ans;
        REP(i, n) {
            if (go[i]) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return;
}
#undef int
int main() {
    init();
    solve();
}