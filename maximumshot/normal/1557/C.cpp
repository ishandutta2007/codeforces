#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const int mod = inf + 7;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int pr = 1;
        int pw2 = 1;
        for (int i = 1; i < n; i++)
            pw2 = (1ll * pw2 * 2) % mod;
        int coef = n % 2 == 0 ? (pw2 + mod - 1) % mod : (pw2 + 1) % mod;
        int res = 0;
        int PW2 = (1ll * pw2 * 2) % mod;
        vector<int> f(k + 1);
        f[0] = 1;
        for (int i = 1; i <= k; i++)
            f[i] = (1ll * f[i - 1] * PW2) % mod;
        for (int l = 0; l < k; l++) {
            if (n % 2 == 0)
                res = (res + 1ll * pr * f[k - l - 1]) % mod;
            pr = (1ll * pr * coef) % mod;
        }
        if (n % 2 == 1)
            res = pr;
        else
            res = (res + pr) % mod;
        if (k == 0)
            res = 1;
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}