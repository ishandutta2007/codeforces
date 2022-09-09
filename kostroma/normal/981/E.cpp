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

using Bitset = bitset<10005>;

struct Query {
    int l, r, x;
};

Bitset result;

void rec(int l, int r, vector<Query> q, Bitset cur_res) {
    if (l + 1 == r) {
        for (auto& cur_q : q) {
            assert(cur_q.l <= l && cur_q.r >= r);
            cur_res = cur_res | (cur_res << cur_q.x);
        }
        result |= cur_res;
        return;
    }
    int m = (l + r) / 2;
    Bitset left_res = cur_res, right_res = cur_res;
    vector<Query> left_q, right_q;
    for (auto& cur_q : q) {
        if (cur_q.l <= l && cur_q.r >= m) {
            left_res = left_res | (left_res << cur_q.x);
        } else if (max(cur_q.l, l) < min(cur_q.r, m)) {
            left_q.push_back(cur_q);
        }
        if (cur_q.l <= m && cur_q.r >= r) {
            right_res = right_res | (right_res << cur_q.x);
        } else if (max(cur_q.l, m) < min(cur_q.r, r)) {
            right_q.push_back(cur_q);
        }
    }
    rec(l, m, left_q, left_res);
    rec(m, r, right_q, right_res);
}

void solve(__attribute__((unused)) bool read) {
    int n, Q;
    //read = false;
    if (read) {
        cin >> n >> Q;
    } else {
        n = 10000;
        Q = 10000;
    }
    vector<Query> q(Q);
    for (int i = 0; i < Q; ++i) {
        if (read) {
            cin >> q[i].l >> q[i].r >> q[i].x;
        } else {
            q[i].x = rand() % n + 1;
            do {
                q[i].l = rand() % n + 1;
                q[i].r = rand() % n + 1;
            } while (q[i].l > q[i].r);
        }
        --q[i].l;
    }
    for (int i = 0; i < result.size(); ++i) {
        result[i] = 0;
    }
    result[0] = 1;
    rec(0, n, q, result);
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (result[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}