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

vector<int> dsu;
vector<int> size;
vector<int> edges;

void init(int n) {
    size.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        size[i] = 1;
    }
    edges.assign(n, 0);
    dsu.resize(n);
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }
}

int find_set(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find_set(dsu[v]);
}

void merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    if (q == w) {
        ++edges[q];
        return;
    }
    dsu[w] = q;
    size[q] += size[w];
    edges[q] += edges[w] + 1;
}

void solve(bool read) {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    vector<map<int, int>> mapa(2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> points[i][j];
            if (!mapa[j].count(points[i][j])) {
                int id = (int)mapa[j].size();
                mapa[j][points[i][j]] = id;
            }
            points[i][j] = mapa[j][points[i][j]];
        }
    }
    init(mapa[0].size() + mapa[1].size());
    for (int i = 0; i < n; ++i) {
        merge(points[i][0], mapa[0].size() + points[i][1]);
        //cout << mapa[0][points[i][0]] << " " << mapa[0].size() + mapa[1][points[i][1]] << endl;
    }
    vector<int> uni, trees;
    for (int i = 0; i < dsu.size(); ++i) {
        if (dsu[i] == i) {
            if (edges[i] >= size[i]) {
                uni.push_back(size[i]);
            } else {
                trees.push_back(size[i]);
            }
        }
    }

    li res = 1;
    const li mod = 1000000007;
    auto get_power = [](int cur) {
        li ans = 1;
        for (int i = 0; i < cur; ++i) {
            ans = ans * 2 % mod;
        }
        return ans;
    };
    for (int x : uni) {
        res = res * get_power(x) % mod;
    }
    for (int x : trees) {
        res = res * (get_power(x) - 1) % mod;
    }
    if (res < 0) {
        res += mod;
    }

    cout << res << endl;

}