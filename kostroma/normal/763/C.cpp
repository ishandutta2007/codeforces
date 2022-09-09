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

//const int mod = 1000000007;


void solve(bool read) {
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    map<int, int> have;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++have[a[i]];
    }
    int mn = 0, mx = 0;
    if (have.size() < m) {
        mn = 0;
    }
    else {
        mn = n;
    }
    for (auto item : have) {
        mn = min(mn, item.second);
        mx = max(mx, item.second);
    }

    if (have.size() == 1) {
        cout << a[0] << " 0\n";
        return;
    }

    assert(mx == 1);

    if (mn == 1) {
        cout << "0 1\n";
        return;
    }

    a.clear();
    for (auto item : have) {
        if (item.second > 0) {
            assert(item.second == 1);
            a.push_back(item.first);
        }
    }

    n = (int)a.size();

    map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    bool swapped = false;
    if (n * 2 > m) {
        a.clear();
        for (int i = 0; i < m; ++i) {
            if (!pos.count(i)) {
                a.push_back(i);
            }
        }
        pos.clear();
        n = (int)a.size();
        for (int i = 0; i < n; ++i) {
            pos[a[i]] = i;
        }
        swapped = true;
    }

    if (n == 1) {
        int cur = a[0];
        if (swapped) {
            cur = (cur + 1) % m;
        }
        cout << cur << " 1\n";
        return;
    }

    vector<char> used(n, false);
    int diff = (a[1] - a[0] + m) % m;
    assert(diff > 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        ++cnt;
        int cur = a[i];
        used[i] = true;
        while (true) {
            int nex = (cur + diff) % m;
            if (!pos.count(nex)) {
                break;
            }
            int ps = pos[nex];
            assert(!used[ps]);
            used[ps] = true;
            cur = nex;
        }
        cur = a[i];
        while (true) {
            int nex = (cur - diff + m) % m;
            if (!pos.count(nex)) {
                break;
            }
            int ps = pos[nex];
            assert(!used[ps]);
            used[ps] = true;
            cur = nex;
        }
    }

    assert(cnt > 0 && cnt < m);
    int d = diff * binpow(cnt, m - 2, m) % m;
    assert(d > 0);

    used.assign(n, false);
    int cur = a[0];
    used[0] = true;
    while (true) {
        int nex = (cur + d) % m;
        if (!pos.count(nex)) {
            break;
        }
        int ps = pos[nex];
        assert(!used[ps]);
        used[ps] = true;
        cur = nex;
    }
    cur = a[0];
    while (true) {
        int nex = (cur - d + m) % m;
        if (!pos.count(nex)) {
            break;
        }
        int ps = pos[nex];
        assert(!used[ps]);
        used[ps] = true;
        cur = nex;
    }

    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            f = false;
            break;
        }
    }

    if (f) {
        int last = cur;
        for (int i = 0; i < n; ++i) {
            if (!pos.count(last)) {
                f = false;
                break;
            }
            pos.erase(last);
            last = (last + d) % m;
        }

        if (f) {
            if (swapped) {
                cur = (cur + n * d) % m;
            }
            cout << cur << " " << d << "\n";
            return;
        }
    }

    cout << "-1\n";

}