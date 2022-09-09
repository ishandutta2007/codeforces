#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
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
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;

struct Parent {
    int last_par = -1;
    int last_coord = -1;
    int shot_coord = -1;
    Parent() : last_par(-1), last_coord(-1), shot_coord(-1) {}
    Parent(int last_par, int last_coord, int shot_coord) : last_par(last_par), last_coord(last_coord), shot_coord(shot_coord) {}
};

const int C = 3000500;
int has[2][C];
int dp[2][C];
Parent pred[2][C];
int next_uk[2][C];

void solve(bool read) {
    int n, m[2], t;
    //read = false;
    if (read) {
        cin >> n >> m[0] >> m[1] >> t;
    } else {
        n = 1000000000;
        m[0] = 500000;
        m[1] = 500000;
        t = 2;
    }
    vector<int> all_coords;
    vector<vector<int>> coords(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            int cur;
            if (read) {
                cin >> cur;
            } else {
                cur = 1000 * (j + 1) + 500 * (i + 1);
            }
            coords[i].push_back(cur);
            all_coords.push_back(cur);
            if (cur < n) {
                all_coords.push_back(cur + 1);
            }
            if (cur > 0) {
                all_coords.push_back(cur - 1);
            }
        }
        sort(all(coords[i]));
        coords[i].erase(unique(all(coords[i])), coords[i].end());
    }
    all_coords.push_back(0);
    //cout << "size: " << all_coords.size() << endl;
    sort(all(all_coords));
    all_coords.erase(unique(all(all_coords)), all_coords.end());
    //vector<vector<int>> dp(2, vector<int>(all_coords.size(), -1));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < all_coords.size(); ++j) {
            dp[i][j] = -1;
            has[i][j] = false;
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int& x : coords[i]) {
            x = lower_bound(all(all_coords), x) - all_coords.begin();
            has[i][x] = true;
        }
    }
    //vector<vector<Parent>> pred(2, vector<Parent>(all_coords.size(), {-1, -1, -1}));
    dp[0][0] = 0;
    int last_par = -1, last_coord = -1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < all_coords.size(); ++j) {
            next_uk[i][j] = -1;
        }
    }
    //vector<vector<int>> next_uk(2, vector<int>(all_coords.size(), -1));
    for (int i = 0; i < 2; ++i) {
        int last = -1;
        for (int j = (int)all_coords.size() - 1; j >= 0; --j) {
            next_uk[i][j] = last;
            if (has[i][j]) {
                last = j;
            }
        }
    }
    vector<int> cur_dp(2, -1);
    for (int i = 0; i < all_coords.size(); ++i) {
        cur_dp.assign(2, -1);
        for (int j = 0; j < 2; ++j) {
            if (!has[j][i]) {
                cur_dp[j] = dp[j][i];
            } else {
                if (dp[j][i] > t) {
                    cur_dp[j] = dp[j][i] - t;
                }
            }
        }
        for (int j = 0; j < 2; ++j) {
            if (cur_dp[j] != -1 && !has[j ^ 1][i]) {
                if (cur_dp[j ^ 1] < min(cur_dp[j], t)) {
                    pred[j ^ 1][i] = {j, i, -1};
                    cur_dp[j ^ 1] = min(cur_dp[j], t);
                }
            }
        }
        /*cout << "coord: " << all_coords[i] << endl;
        for (int j = 0; j < 2; ++j) {
            cout << j << " " << cur_dp[j] << " " << dp[j][i] << endl;
        }*/
        for (int j = 0; j < 2; ++j) {
            if (cur_dp[j] == -1) {
                continue;
            }
            int it = next_uk[j][i];
            if (it == -1) {
                last_par = j;
                last_coord = i;
            } else {
                if (dp[j][it] < cur_dp[j] + all_coords[it] - all_coords[i]) {
                    dp[j][it] = cur_dp[j] + all_coords[it] - all_coords[i];
                    pred[j][it] = {j, i, all_coords[i] + t - cur_dp[j]};
                }
            }
            if (i + 1 < all_coords.size() && !has[j][i + 1]) {
                if (dp[j][i + 1] < cur_dp[j] + all_coords[i + 1] - all_coords[i]) {
                    //cout << j << " " << i + 1 << " " << dp[j][i] << " " << dp[j][i] + all_coords[i + 1] - all_coords[i] << endl;
                    dp[j][i + 1] = cur_dp[j] + all_coords[i + 1] - all_coords[i];
                    pred[j][i + 1] = {j, i, -1};
                }
            }
        }
    }

    if (last_par == -1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";

    vector<pair<int, int>> shots;
    vector<int> swaps;
    int cnt = 0;
    while (last_par != 0 || last_coord != 0) {
        ++cnt;
        assert(cnt < 3e6);
        auto pr = pred[last_par][last_coord];
        if (pr.shot_coord != -1) {
            shots.push_back({last_par, pr.shot_coord});
            //cout << "shoots to " << last_par << " " << last_coord << endl;
        }
        if (pr.last_par != last_par) {
            swaps.push_back(all_coords[pr.last_coord]);
        }
        last_par = pr.last_par;
        last_coord = pr.last_coord;
    }

    reverse(all(shots));
    reverse(all(swaps));

    if (read) {
        cout << swaps.size() << endl;
        for (int x : swaps) {
            cout << x << " ";
        }
        cout << endl;

        cout << shots.size() << endl;
        for (auto item : shots) {
            cout << item.second << " " << item.first + 1 << "\n";
        }
    }


}