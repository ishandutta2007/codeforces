#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n;
const int maxN = 2 * (int)1e5 + 10;
int p[maxN];
int c[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            used[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        int best = n + 1;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                int t = i;
                vector < int > all;
                while (!used[t]) {
                    all.emplace_back(c[t]);
                    used[t] = true;
                    t = p[t];
                }
                for (int j = 1; j <= all.size(); j++) {
                    if (all.size() % j == 0) {
                        bool ok = false;
                        for (int r = 0; r < j; r++) {
                            bool good = true;
                            for (int d = 0; d < all.size() / j; d++) {
                                if (all[j * d + r] != all[r]) {
                                    good = false;
                                    break;
                                }
                            }
                            if (good) {
                                ok = true;
                                break;
                            }
                        }
                        if (ok) {
                            best = min(best, j);
                        }
                    }
                }

            }
        }
        cout << best << '\n';
    }
    return 0;
}