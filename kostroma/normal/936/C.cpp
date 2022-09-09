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
#ifdef AIM
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

string get_sorted(string s) {
    sort(all(s));
    return s;
}

void solve(bool read) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (get_sorted(s) != get_sorted(t)) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;

    auto make_op = [&] (int x) {
        auto q = s.substr(n - x, x);
        reverse(all(q));
        s = q + s.substr(0, n - x);
        ans.push_back(x);

        //cout << "make " << x << " new_s: " << s << endl;

    };
    vector<int> positions;
    int l = (n - 1) / 2;
    int r = l + 1;
    while (l >= 0 || r < n) {
        if (l >= 0) {
            positions.push_back(l);
            --l;
        }
        if (r < n) {
            positions.push_back(r);
            ++r;
        }
    }
    int pref = 0;
    string desire;
    int cnt = 0;
    for (int pos : positions) {
        if (cnt % 2 == 0) {
            desire.insert(desire.begin(), t[pos]);
        } else {
            desire += t[pos];
        }
        ++cnt;
        int need = -1;
        for (int j = pref; j < n; ++j) {
            if (s[j] == t[pos]) {
                need = j;
                break;
            }
        }
        assert(need != -1);
        make_op(n - need);
        need = n - 1 - need;
        need += pref + 1;
        if (need < n) {
            make_op(n - need);
        }
        make_op(n);
        ++pref;

        //cout << "s: " << s << " sym: " << t[pos] << endl;
        //cout << "desire: " << desire << " have: " << s.substr(0, desire.length()) << endl;
    }

    if (s != t) {
        auto q = s;
        reverse(all(q));
        assert(q == t);
        make_op(n);
    }

    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

}