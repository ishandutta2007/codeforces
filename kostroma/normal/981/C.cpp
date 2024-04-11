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

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= 3) {
            if (root != -1) {
                cout << "No\n";
                return;
            }
            root = i;
        }
    }
    if (root == -1) {
        root = 0;
    }
    cout << "Yes\n";
    cout << g[root].size() << "\n";
    for (int st : g[root]) {
        int cur = st;
        int prev = root;
        while (true) {
            bool f = false;
            for (int to : g[cur]) {
                if (to != prev) {
                    f = true;
                    prev = cur;
                    cur = to;
                    break;
                }
            }
            if (!f) {
                break;
            }
        }
        cout << root + 1 << " " << cur + 1 << "\n";
    }

}