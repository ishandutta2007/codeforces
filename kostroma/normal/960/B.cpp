#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
//    cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
    int n, k[2];
    cin >> n >> k[0] >> k[1];
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        a[i] -= b[i];
        a[i] = abs(a[i]);
    }
    int K = k[0] + k[1];
    for (int j = 0; j < K; ++j) {
        int max_id = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[max_id]) {
                max_id = i;
            }
        }
        --a[max_id];
        if (a[max_id] < 0) {
            a[max_id] = -a[max_id];
        }
    }
    int res = 0;
    for (int x : a) {
        res += x * x;
    }
    cout << res << "\n";
}