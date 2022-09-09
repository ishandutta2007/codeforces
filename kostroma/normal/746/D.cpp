#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

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


void solve() {
    int n, k, a[2];
    cin >> n >> k >> a[0] >> a[1];
    int last = -1;
    vector<int> res;
    int group = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        if (a[1] > a[0]) {
            cur = 1;
        }
        if (last != cur) {
            res.push_back(cur);
            group = 1;
            --a[cur];
        }
        else {
            if (group < k) {
                ++group;
                res.push_back(cur);
                --a[cur];
            }
            else {
                res.push_back(cur ^ 1);
                --a[cur ^ 1];
                group = 1;
            }
        }
        last = res.back();
    }
    
    if (a[0] || a[1]) {
        cout << "NO\n";
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (res[i]) {
            cout << "B";
        }
        else {
            cout << "G";
        }
    }
    

}