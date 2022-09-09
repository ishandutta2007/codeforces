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
#ifdef AIM
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

struct MyS {
    vector<int> a;
    vector<vector<int>> poses;
    vector<vector<int>> pref_sum;
    size_t size() const {
        return a.size();
    }
    void scan(bool read) {
        string s;
        if (read) {
            cin >> s;
        } else {
            int len = rand() % 4 + 1;
            for (int i = 0; i < len; ++i) {
                s += "AB"[rand() % 2];
            }
        }
        poses.resize(2);
        a.resize(s.length());
        pref_sum.push_back(vector<int>(2, 0));
        for (int i = 0; i < a.size(); ++i) {
            a[i] = (s[i] == 'A');
            poses[a[i]].push_back(i);
            pref_sum.push_back(pref_sum.back());
            ++pref_sum.back()[a[i]];
        }
    }
    int get_zeroes(int l, int r) {
        return pref_sum[r][0] - pref_sum[l][0];
    }
    int get_suf(int l, int r) {
        auto it = lower_bound(all(poses[0]), r);
        if (it != poses[0].begin()) {
            --it;
            return min(r - l, r - 1 - *it);
        } else {
            return r - l;
        }
    }
    vector<int> get_segment(int l, int r) {
        return vector<int>(a.begin() + l, a.begin() + r);
    }
};

bool get_stupid(vector<int> a, vector<int> b) {
    map<vector<int>, vector<int>> have;
    have[a] = a;
    queue<vector<int>> q;
    q.push(a);

    vector<int> v;
    auto ins = [&] (vector<int> cur) {
        if (!have.count(cur)) {
            have[cur] = v;
            q.push(cur);
        }
    };

    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (v == b) {
            break;
        }
        if (v.size() > 3 * a.size()) {
            continue;
        }
        for (int i = 0; i + 3 <= v.size(); ++i) {
            if (v[i] == 1 && v[i + 1] == 1 && v[i + 2] == 1) {
                auto nex = v;
                nex.erase(nex.begin() + i, nex.begin() + i + 3);
                ins(nex);
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 1) {
                auto nex = v;
                nex[i] = 0;
                nex.insert(nex.begin() + i, 0);
                ins(nex);
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                auto nex = v;
                nex.insert(nex.begin() + i, 1);
                ins(nex);
            }
        }
    }

    /*v = b;
    while (v != a) {
        for (int x : v) {
            cout << x;
        }
        cout << "\n";
        v = have[v];
    }
    for (int x : v) {
        cout << x;
    }
    cout << "\n";*/

    return (bool)have.count(b);
}

void solve(bool read) {
    MyS S, T;
    S.scan(read);
    T.scan(read);
    int Q;
    if (read) {
        cin >> Q;
    } else {
        Q = 100;
    }
    while (Q--) {
        int a, b, c, d;
        if (read) {
            cin >> a >> b >> c >> d;
        } else {
            do {
                a = rand() % S.size() + 1;
                b = rand() % S.size() + 1;
            } while (a > b);
            do {
                c = rand() % T.size() + 1;
                d = rand() % T.size() + 1;
            } while (c > d);
        }
        --a; --c;
        int s_suf = S.get_suf(a, b), t_suf = T.get_suf(c, d);
        int s_zeroes = S.get_zeroes(a, b), t_zeroes = T.get_zeroes(c, d);
        bool res = false;
        if (s_suf < t_suf || s_zeroes > t_zeroes || (s_zeroes + t_zeroes) % 2) {
            res = false;
        } else {
            if (s_suf == t_suf && (s_zeroes == t_zeroes || s_zeroes > 0)) {
                res = true;
            }
            else if (s_suf > t_suf && (s_suf - t_suf) % 3 == 0) {
                res = true;
            }
            else if (s_suf > t_suf && 2 + s_zeroes <= t_zeroes) {
                res = true;
            }
        }
        if (!read) {
            if (res != get_stupid(S.get_segment(a, b), T.get_segment(c, d))) {
                cout << "FOUND" << endl;
                cout << "res: " << res << " stup: " << get_stupid(S.get_segment(a, b), T.get_segment(c, d)) << endl;
                for (int i = 0; i < S.size(); ++i) {
                    cout << S.a[i];
                }
                cout << endl;
                for (int i = 0; i < T.size(); ++i) {
                    cout << T.a[i];
                }
                cout << endl;
                cout << a << " " << b << " " << c << " " << d << endl;
                exit(0);
            }
            cout << "ok ";
        } else {
            cout << res;
        }

    }
    cout << "\n";

}