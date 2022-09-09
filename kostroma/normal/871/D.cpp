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

#define int li
//const int mod = 1000000007;

const int C = 10000500;

int exact[C];
int lp[C];
int nu[C];
int by_min_prime[C];

void solve(bool read) {
    vector<int> pr;
    for (int i = 2; i < C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < C; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    nu[1] = 1;
    for (int i = 2; i < C; ++i) {
        nu[i] = -nu[i / lp[i]];
        if (i / lp[i] % lp[i] == 0) {
            nu[i] = 0;
        }
        if (i < 10) {
            //cout << nu[i] << " ";
        }
    }
    //cout << endl;

    int n;
    cin >> n;

    /*vector<vector<int>> matrix(n + 1, vector<int>(n + 1, (int)10));
    map<int, int> by_gcd;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                matrix[i][j] = 0;
            } else if (gcd(i, j) > 1) {
                matrix[i][j] = 1;
                if (i < j) {
                    by_gcd[gcd(i, j)]++;
                }
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    int all_sum = 0;
    map<int, int> mapa;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            //cout << matrix[i][j] << " ";
            if (matrix[i][j] != 10 && i < j) {
                all_sum += matrix[i][j];
                ++mapa[matrix[i][j]];
            }
        }
    }
    cout << "Sum: " << all_sum << endl;

    for (auto item : mapa) {
        cout << item.first << " " << item.second << endl;
    }*/

    for (int i = 1; i <= n; ++i) {
        exact[i] = (n / i) * ((n / i) - 1) / 2;
    }
    for (int d = n; d >= 1; --d) {
        for (int nex = 2 * d; nex <= n; nex += d) {
            exact[d] -= exact[nex];
        }
        //cout << d << " " << exact[d] << " " << by_gcd[d] << endl;
    }

    int all_pairs = (n - 1) * (n - 2) / 2;
    int with_gcd = 0;
    for (int d = 2; d <= n; ++d) {
        with_gcd += exact[d];
    }

    //cout << all_pairs << " " << with_gcd << endl;

    int res = with_gcd + (all_pairs - with_gcd) * 2;

    //cout << res << endl;

    int cnt_large_primes = 0;
    for (int p : pr) {
        if (p > n) {
            break;
        }
        if (p * 2 > n) {
            ++cnt_large_primes;
        }
    }

    //cout << cnt_large_primes << endl;

    //cout << res << endl;

    res -= 2 * cnt_large_primes * (cnt_large_primes - 1) / 2;
    res -= 2 * cnt_large_primes * (n - 1 - cnt_large_primes);

    //cout << res << endl;

    //cout << res << endl;

    for (int i = 2; i <= n; ++i) {
        if (i > lp[i]) {
            ++by_min_prime[lp[i]];
        }
    }
    int uk = C - 1;
    int sum = 0;
    int pr_uk = (int)pr.size() - 1;
    int tree_sum = 0;
    for (int i = 0; i < pr.size(); ++i) {
        int p = pr[i];
        if (2 * p > n) {
            break;
        }
        while (p * (uk - 1) > n) {
            --uk;
            sum += by_min_prime[uk];
        }
        //cout << p << " " << sum << " " << res << endl;
        res += sum;
        tree_sum += sum;
        //cout << "add_sum: " << sum << " " << p << " " << uk << endl;

        while (pr_uk > 0 && p * pr[pr_uk - 1] > n) {
            --pr_uk;
        }
        if (pr_uk < i) {
            res += i - pr_uk;
            tree_sum += i - pr_uk;
            //cout << "add: " << i - pr_uk << pr[i] << " " << pr[pr_uk] << endl;
        }
    }

    //cout << "3: " << tree_sum << endl;

    cout << res << endl;

}