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

#define int li

const int shift = 1 << 20;

int tree[2 * shift];

int rsq(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (l & 1) {
        return tree[l] + rsq(l + 1, r);
    }
    if (r & 1) {
        return tree[r - 1] + rsq(l, r - 1);
    }
    return rsq(l / 2, r / 2);
}

int get_sum(int l, int r) {
    return rsq(l + shift, r + shift);
}

void update(int v, int val) {
    v += shift;
    tree[v] = val;
    v /= 2;
    while (v) {
        tree[v] = tree[2 * v] + tree[2 * v+ 1];
        v /= 2;
    }
}

int n;
int get_res(int l, int r) {
    if (l < r) {
        return get_sum(l, r);
    }
    else {
        return get_sum(l, n) + get_sum(0, r);
    }
}

void solve(bool read) {
    int k;
    cin >> n >> k;
    k = min(k, n - k);
    int cur = 0;
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int nex = (cur + k) % n;
        int add = get_res(cur, nex) * 2;
        if (cur > nex && nex) {
            --add;
        }
        ++add;
        res += add;
        cout << res << " ";
        update(cur, 1);
        cur = nex;
    }

}