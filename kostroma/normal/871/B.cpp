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

vector<int> p;
vector<int> rev;

void gen(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    random_shuffle(p.begin(), p.end());
    rev.resize(n);
    for (int i = 0; i < n; ++i) {
        rev[p[i]] = i;
    }
    cout << "generated" << endl;
    for (int x : p) {
        cout << x << " ";
    }
    cout << endl;
}

int get_res(int i, int j) {
    cout << "? " << i << " " << j << endl;
    //return p[i] ^ rev[j];
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}

int xor_cross[5010][5010];
int xor_p[5010][5010];

void solve(bool read) {
    int n;
    cin >> n;
    //gen(n);

    if (n == 1) {
        cout << "!" << endl;
        cout << 1 << endl;
        cout << 0 << endl;
        return;
    }

    vector<int> xors_rev(n), xors_p(n);
    for (int i = 0; i < n; ++i) {
        xors_p[i] = get_res(i, 0);
        xors_rev[i] = get_res(0, i);
    }
    //vector<vector<int>> xor_cross(n, vector<int>(n));
    //vector<vector<int>> xor_p(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            xor_cross[i][j] = (xors_p[i] ^ xors_rev[j] ^ xors_p[0]);
            xor_p[i][j] = (xors_p[i] ^ xors_p[j]);
        }
    }
    int cnt = 0;
    vector<int> answer;
    vector<char> used(n, false);
    vector<int> res(n);
    for (int x = 0; x < n; ++x) {
        used.assign(n, false);
        bool good = true;
        for (int i = 0; i < n; ++i) {
            res[i] = xor_p[x][i];
            if (res[i] < 0 || res[i] >= n) {
                good = false;
                break;
            }
            if (used[res[i]]) {
                good = false;
                break;
            }
            used[res[i]] = true;
        }
        if (good) {
            vector<int> cur_rev(n);
            for (int i = 0; i < n; ++i) {
                cur_rev[res[i]] = i;
            }
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i && j) {
                        break;
                    }
                    if (xor_cross[i][j] != (res[i] ^ cur_rev[j])) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                ++cnt;
                if (answer.empty()) {
                    answer = res;
                }
            }
        }
    }
    assert(cnt > 0);
    cout << "!" << endl;
    cout << cnt << endl;
    for (int x : answer) {
        cout << x << " ";
    }
    cout << endl;
}