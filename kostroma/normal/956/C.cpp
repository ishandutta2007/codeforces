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
    int n;
    cin >> n;
    vector<int> a(n);
    set<pair<int, int>> have;
    int pref_max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        have.insert({-a[i], i});
    }
    int last_pos = n;
    int last_max = -1;
    li res = 0;
    while (!have.empty()) {
        auto cur_pos = have.begin()->second;
        int cur_max = a[cur_pos];
        if (last_pos == n) {
            last_max = cur_max + 1;
        }
        for (int i = last_pos - 1; i > cur_pos; --i) {
            res += last_max - a[i] - 1;
            //cout << "add pos: " << i << " val: " << last_max - a[i] - 1 << endl;
            if (last_max > cur_max + 1) {
                --last_max;
            }
            have.erase({-a[i], i});
        }
        have.erase({-a[cur_pos], cur_pos});
        res += last_max - cur_max - 1;
        --last_max;
        last_pos = cur_pos;
    }

    cout << res << "\n";

}