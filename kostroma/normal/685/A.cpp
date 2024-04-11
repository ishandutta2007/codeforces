#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
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
        solve();
        ++testNumber;
        //++timer;
    }

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

void precalc() {


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

//#define int li

//const int mod = 1000000007;

//#define double ld

int get(int n) {
    if (!n) {
        return 1;
    }
    int res = 0;
    while (n) {
        ++res;
        n /= 7;
    }
    return res;
}

vector<int> get_vec(int n, int sz) {
    vector<int> res;
    for (int i = 0; i < sz; ++i) {
        res.push_back(n % 7);
        n /= 7;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt1 = get(n - 1);
    int cnt2 = get(m - 1);
    if (cnt1 + cnt2 > 7) {
        cout << "0\n";
        return;
    }
    int res = 0;
    vector<int> vec, vec1;
    vector<int> cnt(7);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vec = get_vec(i, cnt1), vec1 = get_vec(j, cnt2);
            cnt.assign(7, 0);
            for (int to : vec) {
                ++cnt[to];
            }
            for (int to : vec1) {
                ++cnt[to];
            }
            bool f = true;
            for (int w = 0; w < 7; ++w) {
                if (cnt[w] > 1) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ++res;
            }
        }
    }
    cout << res << "\n";
}