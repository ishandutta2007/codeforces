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
    //cin >> t;
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

void precalc() {
}

//#define int li
//const int mod = 1000000007;

const int INF = (int)1e9;

struct SegTree {
    int shift;
    vector<int> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, INF);
    }
    void update(int v, int val) {
        v += shift;
        tree[v] = min(tree[v], val);
        v /= 2;
        while (v) {
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
            v /= 2;
        }
    }
    int get_res(int l, int r) {
        l += shift;
        r += shift;
        int res = INF;
        while (l < r) {
            if (l & 1) {
                res = min(res, tree[l++]);
                continue;
            }
            if (r & 1) {
                res = min(res, tree[--r]);
                continue;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

void solve(__attribute__((unused)) bool read) {
    int n, len;
    //read = false;
    if (read) {
        cin >> n >> len;
    } else {
        n = 200000;
        len = 1000000000;
    }
    vector<int> men(n), women(n);
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> men[i];
        } else {
            men[i] = rand() % len;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> women[i];
        } else {
            women[i] = rand() % len;
        }
    }
    sort(all(women));
    for (int i = 0; i < n; ++i) {
        women.push_back(women[i] + len);
    }

    int L = -1, R = len / 2;
    while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<pair<int, int>> segs;
        for (int x : men) {
            int l = x - M, r = x + M;
            if (len == 2 * M) {
                ++l;
            }
            if (l < 0) {
                l += len;
                r += len;
            }
            segs.push_back({l, r});
            if (r < len) {
                segs.push_back({l + len, r + len});
            }
        }
        sort(all(segs));
        bool flag = true;
        vector<int> best_diff(segs.size());
        for (int i = (int)segs.size() - 1; i >= 0; --i) {
            int before = upper_bound(all(women), segs[i].second) - women.begin();
            best_diff[i] = before - i;
            if (i + 1 < segs.size() && segs[i + 1].first <= segs[i].second) {
                relax_min(best_diff[i], best_diff[i + 1]);
            }
            int before_left = lower_bound(all(women), segs[i].first) - women.begin();
            int cur_score = best_diff[i] - before_left + i;
            if (cur_score <= 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << "\n";
}