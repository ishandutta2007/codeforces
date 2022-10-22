#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int slow(int n, int M) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    set<vector<int>> Q;
    do {
        vector<int> seq, used(n);
        for (int i : perm) {
            if (i > 0 && used[i - 1] && i + 1 < n && used[i + 1])
                continue;
            used[i] = 1;
            seq.push_back(i);
        }
        Q.insert(seq);
    } while (next_permutation(perm.begin(), perm.end()));
    return (int) Q.size() % M;
}

inline int _binpow(int x, int pw, int M) {
    int res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1)
            res = (1ll * res * tmp) % M;
        tmp = (1ll * tmp * tmp) % M;
        pw >>= 1;
    }
    return res;
}

int fast(int n, int M) {

    vector<int> pw2(n + 1);
    pw2[0] = 1;
    for (int i = 1; i <= n; i++)
        pw2[i] = (1ll * pw2[i - 1] * 2) % M;

    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (1ll * fact[i - 1] * i) % M;
    vector<int> rfact(n + 1);
    for (int i = 0; i <= n; i++)
        rfact[i] = _binpow(fact[i], M - 2, M);

    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int l = 0; l <= n; l++) {
        for (int r = 0; r <= n; r++) {
            if (l == 0 && r == 0) {
                g[l][r] = 1;
            } else if (l == 0) {
                g[l][r] = g[l][r - 1];
            } else if (r == 0) {
                g[l][r] = g[l - 1][r];
            } else {
                g[l][r] = (g[l - 1][r] + g[l][r - 1]) % M;
            }
        }
    }

    vector<int> f(n + 1);
    for (int k = 1; k <= n; k++) {
        for (int l = 0; l < k; l++) {
            int r = k - l - 1;
            f[k] = (f[k] + g[l][r]) % M;
        }
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 2; i <= n + 1; i++) {
        for (int c = 1; c <= n; c++) {
            for (int j = i - 2; j >= 0; j--) {
                int k = i - j - 1;
                dp[i][c] = (dp[i][c] + (1ll * dp[j][c - 1] * f[k] % M) * rfact[k] % M) % M;
            }
        }
    }

    int res = 0;
    for (int c = 1; c <= n; c++) {
        res = (res + 1ll * dp[n + 1][c] * fact[n - (c - 1)]) % M;
    }

    return res;
}

void work() {
    int n, M;
    cin >> n >> M;
    int fs = fast(n, M);
    cout << fs << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    help();

    return 0;
}