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

int n, m;
vector<string> matrix;

bool correct(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != '#';
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve(bool read) {
    cin >> n >> m;
    matrix.resize(n);
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    string path;
    cin >> path;
    vector<int> perm = {0, 1, 2, 3};
    int ans = 0;
    do {
        int x = sx, y = sy;
        bool f = true;
        for (char c : path) {
            int id = perm[c - '0'];
            x += dx[id];
            y += dy[id];
            if (!correct(x, y)) {
                f = false;
                break;
            } else if (matrix[x][y] == 'E') {
                break;
            }
        }
        if (f && matrix[x][y] == 'E') {
            ++ans;
        }
    }
    while (next_permutation(all(perm)));
    cout << ans << endl;
}