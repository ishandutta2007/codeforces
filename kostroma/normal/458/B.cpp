#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;


int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
    cout.sync_with_stdio(0);
    //precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    start = clock();
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve();
        //++timer;
    }

#ifdef room111
    cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int unsigned long long

int m, n;
int a[100500], b[100500];

void solve() {
    cin >> m >> n;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        sumA += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sumB += b[i];
    }

    sort(a, a + m);
    sort(b, b + n);

    int ans = 1e18;

    int pref = 0;
    for (int k = 0; k < m; ++k) {
        ans = min(ans, sumB * (m - k) + pref);
        pref += a[k];
    }

    pref = 0;
    for (int k = 0; k < n; ++k) {
        ans = min(ans, sumA * (n - k) + pref);
        pref += b[k];
    }

    cout << ans;

}