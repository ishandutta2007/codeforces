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
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    vector<vector<int>> have;
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
        vector<int> vec;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '#') {
                vec.push_back(j);
            }
        }
        have.push_back(vec);
    }
    sort(all(have));
    have.erase(unique(all(have)), have.end());
    bool flag = true;
    for (int i = 0; i < have.size(); ++i) {
        set<int> con;
        for (int x : have[i]) {
            con.insert(x);
        }
        for (int j = i + 1; j < have.size(); ++j) {
            for (int x : have[j]) {
                if (con.count(x)) {
                    flag = false;
                }
            }
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
}