#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

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

void precalc() {

}

//#define int li

//const int mod = 1000000007;


void solve(bool read) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> deg(n);
    int roots = 0;
    vector<int> num_root(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (a[i] == i) {
            num_root[i] = roots++;
        }
        else {
            ++deg[a[i]];
        }
    }

    vector<int> g(n), h(roots);
    for (int i = 0; i < n; ++i) {
        if (a[i] != i && a[a[i]] != a[i]) {
            cout << "-1\n";
            return;
        }
        if (a[i] == i) {
            h[num_root[i]] = i;
            g[i] = num_root[i];
        }
        else {
            g[i] = num_root[a[i]];
        }
    }

    cout << roots << "\n";
    for (int i = 0; i < n; ++i) {
        cout << g[i] + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < roots; ++i) {
        cout << h[i] + 1 << " ";
    }
    cout << endl;

}