//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxP = 1e6 + 10;
int lp[maxP];
int n;
/*int cur[maxP][maxP];
int D[maxP];
int need[maxP];
int solve(int n) {
    memset(D, 0, sizeof D);
    memset(need, 0, sizeof need);
    memset(lp, 0, sizeof lp);
    memset(cur, 0, sizeof cur);
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j <= n; j += i) {
                lp[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int c = i;
        for (int z = 1; z <= n; z++) cur[i][z] = cur[i - 1][z];
        while (c > 1) {
            int p = lp[c];
            int ex = 0;
            while (c % p == 0) {
                c /= p;
                ex ^= 1;
            }
            cur[i][p] ^= ex;
        }
        for (int z = 1; z <= n; z++) {
            need[z] ^= cur[i][z];
        }
    }
    auto do_xr = [&](int i) {
        for (int z = 1; z <= n; z++) {
            D[z] ^= cur[i][z];
        }
    };
    auto are_eq = [&] {
        for (int z = 1; z <= n; z++) {
            if (D[z] != need[z]) return false;
        }
        return true;
    };
    if (are_eq()) {
        cout << 0 << '\n';
        return 0;
    }
    for (int x = 1; x <= n; x++) {
        memset(D, 0, sizeof D);
        do_xr(x);
        if (are_eq()) {
            cout << x << " " << 1 << '\n';
            return 0;
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = x + 1; y <= n; y++) {

            memset(D, 0, sizeof D);
            do_xr(x);
            do_xr(y);
            if (are_eq()) {
                cout << x << " " << y << " " << 2 << '\n';
                return 0;
            }
        }
    }


    for (int x = 1; x <= n; x++) {
        for (int y = x + 1; y <= n; y++) {
            for (int z = y + 1; z <= n; z++) {
                memset(D, 0, sizeof D);
                do_xr(x);
                do_xr(y);
                do_xr(z);
                if (are_eq()) {
                    cout << x << " " << y << " " << z << " " << 3 << '\n';
                    return 0;
                }
            }
        }
    }
    assert(false);
    return -1;
}*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef unsigned long long ull;
ll myRand(ll B) {
    return (ull)rng() % B;
}
ull val_p[maxP];
ull val[maxP];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    /*for (int n = 1; n <= 500; n++) {
        solve(n);
    }*/
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n" << 1;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            val_p[i] = rng();
            for (int j = 2 * i; j <= n; j += i) {
                lp[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        val[i] = val[i - 1];
        int c = i;
        while (c > 1) {
            int p = lp[c];
            while (c % p == 0) {
                c /= p;
                val[i] ^= val_p[p];
            }
        }
    }
    ull s = 0;
    for (int i = 1; i <= n; i++) {
        s ^= val[i];
    }
    auto check_0 = [&]() {
        if (s == 0) {
            cout << n << '\n';
            for (int i = 1; i <= n; i++) cout << i << " ";
            cout << '\n';
            exit(0);
        }
    };
    check_0();
    auto check_1 = [&]() {
        for (int i = 1; i <= n; i++) {
            if (s == val[i]) {
                cout << n - 1 << '\n';
                for (int j = 1; j <= n; j++) {
                    if (j == i) continue;
                    cout << j << " ";
                }
                cout << '\n';
                exit(0);
            }
        }
    };
    check_1();

    vector<pair<ull,int>> all;
    for (int i = 1; i <= n; i++) {
        all.emplace_back(val[i], i);
    }
    sort(all.begin(), all.end());
    auto check_2 = [&]() {
        for (int i = 1; i <= n; i++) {
            ull res = s ^ val[i];
            auto pt = lower_bound(all.begin(), all.end(), make_pair(res, -1)) - all.begin();
            if (pt != all.size() && all[pt].first == res) {
                cout << n - 2 << '\n';
                for (int j = 1; j <= n; j++) {
                    if (j == i || j == all[pt].second) continue;
                    cout << j << " ";
                }
                exit(0);
            }
        }
    };
    check_2();
    auto check_3 = [&]() {
        int A = n;
        int B = n / 2 + 2;
        for (int z = 0; ; z++) {
            int to_del = 0;
            if (z % 2 == 0) {
                to_del = A - z / 2;
            }
            else {
                to_del = B - z / 2;
            }
            if (to_del < 1 || to_del > n) continue;
            ull ns = s ^ val[to_del];
            for (int i = 1; i <= n; i++) {
                if (i == to_del) continue;
                ull res = ns ^ val[i];
                auto pt = lower_bound(all.begin(), all.end(), make_pair(res, -1)) - all.begin();
                if (pt != all.size() && all[pt].first == res) {
                    cout << n - 3 << '\n';
                    for (int j = 1; j <= n; j++) {
                        if (j == i || j == all[pt].second || j == to_del) continue;
                        cout << j << " ";
                    }
                    exit(0);
                }
            }
        }
    };
    check_3();
    assert(false);
    return 0;
}