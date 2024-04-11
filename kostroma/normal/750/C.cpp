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
    vector<int> div(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> div[i];
    }
    int pref = 0;
    int mn = -1e9;
    int mx = 1e9;
    int border = 1900;
    if (div[0] == 2) {
        mx = border - 1;
    }
    else {
        mn = border;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (div[i] == 1 && div[i + 1] == 1) {
            if (c[i] < 0) {
                mn = max(mn, border - c[i] - pref);
            }
        }
        if (div[i] == 1 && div[i + 1] == 2) {
            if (c[i] >= 0) {
                cout << "Impossible\n";
                return;
            }
            mx = min(mx, border - 1 - c[i] - pref);
        }
        if (div[i] == 2 && div[i + 1] == 1) {
            if (c[i] <= 0) {
                cout << "Impossible\n";
                return;
            }
            mn = max(mn, border - pref - c[i]);
        }
        if (div[i] == 2 && div[i + 1] == 2) {
            if (c[i] > 0) {
                mx = min(mx, border - 1 - pref - c[i]);
            }
        }
        pref += c[i];
    }

    if (mn > mx) {
        cout << "Impossible\n";
        return;
    }

    if (mx > 1e8) {
        cout << "Infinity\n";
        return;
    }

    pref += c.back();

    cout << mx + pref << endl;


}