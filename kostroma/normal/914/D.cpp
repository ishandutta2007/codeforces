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
    cout.sync_with_stdio(0);
    cin.tie(0);
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

struct SegTree {
    int shift;
    vector<int> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, 0);
    }
    void update(int v, int val) {
        v += shift;
        tree[v] = val;
        v /= 2;
        while (v) {
            tree[v] = gcd(tree[2 * v], tree[2 * v + 1]);
            v /= 2;
        }
    }
    void rmq(int l, int r, vector<int>& vec) {
        if (l >= r) {
            return;
        }
        if (l & 1) {
            vec.push_back(l);
            return rmq(l + 1, r, vec);
        }
        if (r & 1) {
            vec.push_back(r - 1);
            return rmq(l, r - 1, vec);
        }
        return rmq(l / 2, r / 2, vec);
    }
    bool get_res(int l, int r, int x) {
        vector<int> vec;
        rmq(l + shift, r + shift, vec);
        vector<int> bad;
        for (int v : vec) {
            if (tree[v] % x) {
                bad.push_back(v);
            }
        }
        if (bad.size() > 1) {
            return false;
        }
        if (bad.empty()) {
            return true;
        }
        int v = bad[0];
        while (v < shift) {
            if (tree[2 * v] % x != 0 && tree[2 * v + 1] % x != 0) {
                return false;
            }
            if (tree[2 * v] % x != 0) {
                v = 2 * v;
                continue;
            }
            if (tree[2 * v + 1] % x != 0) {
                v = 2 * v + 1;
                continue;
            }
            break;
        }
        return true;
    }
};

void solve(bool read) {
    int n;
    cin >> n;
    vector<int> a(n);
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tree.update(i, a[i]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (tree.get_res(l, r, x)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int pos, y;
            cin >> pos >> y;
            --pos;
            tree.update(pos, y);
        }
    }


}