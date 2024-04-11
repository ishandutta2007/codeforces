#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
inline int add(int a, int b) {
    return (a += b) >= MOD ? a - MOD : a;
}
inline int sub(int a, int b) {
    return (a -= b) < 0 ? a + MOD : a;
}
inline int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}
inline int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

const int N = 14;
const int NN = 1 << 14;
int n;
int a[N];
int e[N][N];
int pwin[N][NN];
int pscc[NN];

int prob_win_all(int msk1, int msk2) {
    int res = 1;
    // assert((msk1 & msk2) == 0);
    for (int h = 0 ; h < n ; ++ h)
        if (msk1 >> h & 1) res = mul(res, pwin[h][msk2]);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];

    for (int i = 0 ; i < n ; ++ i)
    for (int j = i + 1 ; j < n ; ++ j) {
        e[i][j] = mul(a[i], power(a[i] + a[j], MOD - 2));
        e[j][i] = sub(1, e[i][j]);
    }

    for (int v = 0 ; v < n ; ++ v) {
        for (int msk = 0; msk < (1 << n) ; ++ msk) {
            pwin[v][msk] = 1;
            for (int i = 0 ; i < n ; ++ i)
                if (msk >> i & 1) pwin[v][msk] = mul(pwin[v][msk], e[v][i]);
        }
    }
    /**
        for each mask calculate two things
        The probability that nodes in mask form the root of scc P(msk)
        Inclusion-exclusion: P(msk) = 1 - sum(P(sub_msk) * G(sub_msk, msk ^ sub_msk))
        G simply calculated by win_all function. In essence, it's just prob that all nodes in one side formed complete bipartite with otherside.
        For the answer, for each mask after forcing it to be root of scc, other edges will be force by the same function G(msk, 1 << n - 1 ^ msk)
    */

    int ans = 0;

    for (int msk = 1 ; msk < (1 << n) ; ++ msk) {
        pscc[msk] = 1;
        for (int sub_msk = msk & (msk - 1) ; sub_msk > 0; sub_msk = (sub_msk - 1) & msk) {
            int offset = mul(pscc[sub_msk], prob_win_all(sub_msk, msk ^ sub_msk));
            pscc[msk] = sub(pscc[msk], offset);
        }
        int f = mul(pscc[msk], prob_win_all(msk, (1 << n) - 1 - msk));
        f = mul(f, __builtin_popcount(msk));
        ans = add(ans, f);
    }
    cout << ans << '\n';
}