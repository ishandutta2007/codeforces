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

//#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
    string s;
    cin >> s;
    int n[3] = {0, 0, 0};
    int uk = 0;
    for (int i = 0; i < 3; ++i) {
        char c = (char)('a' + i);
        while (uk < s.length() && s[uk] == c) {
            ++uk;
            ++n[i];
        }
    }
    if (uk == s.length() && n[0] > 0 && n[1] > 0 && (n[0] == n[2] || n[1] == n[2])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}