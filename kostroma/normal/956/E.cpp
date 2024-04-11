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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> poh, important;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (l > sum) {
        cout << "0\n";
        return;
    }
    r = min(r, sum);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c) {
            important.push_back(a[i]);
        } else {
            poh.push_back(a[i]);
        }
    }
    vector<int> can(sum + 1, 0);
    can[0] = 1;
    for (int x : poh) {
        for (int cur = sum - x; cur >= 0; --cur) {
            if (can[cur]) {
                can[cur + x] = 1;
            }
        }
    }
    const int INF = (int)1e9;
    vector<int> dp(sum + 1, INF);
    sort(all(important));
    vector<int> pref_sum(important.size() + 1);
    for (int i = 0; i < important.size(); ++i) {
        pref_sum[i + 1] = pref_sum[i] + important[i];
    }
    for (int i = 0; i < can.size(); ++i) {
        if (can[i]) {
            dp[i] = 0;
        }
    }
    int ans = 0;
    for (int i = (int)important.size(); i >= 0; --i) {
        if (i < important.size()) {
            for (int cur = sum - important[i]; cur >= 0; --cur) {
                dp[cur + important[i]] = min(dp[cur + important[i]], dp[cur] + 1);
            }
        }
        int uk = i;
        for (int pref = l; pref <= r; ++pref) {
            if (dp[pref] == INF) {
                continue;
            }
            int rest = r - pref;
            while (pref_sum[uk] > rest) {
                --uk;
            }
            int cur_res = uk;
            if (uk < i || uk == i && dp[pref] < (int)important.size() - i) {
                ++cur_res;
            }
            ans = max(ans, cur_res);
        }
    }

    cout << ans << "\n";

}