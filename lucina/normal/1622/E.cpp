#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 12;
int n, m;
string p[K];
int64_t ans;
int bst_msk;
int x[N];
array <int, 2> cst[N];
int ans_perm[N];
int val[N];
int pre_msk[N];
int pcnt[1 << K];

void brute(int msk) {
    int64_t s = 0;
    for (int i = 0 ; i < n ; ++ i)
        s += (msk >> i & 1) ? x[i] : (-x[i]);
    for (int i = 0 ; i < m ; ++ i) {
        int msk_here = pre_msk[i];
        int bal =  pcnt[msk_here] - 2 * pcnt[msk & msk_here];
        cst[i] = {bal, i};
    }
    stable_sort(cst, cst + m);
    for (int i = 0 ; i < m ; ++ i) {
        s += 1ll * (i + 1) * cst[i][0];
    }
    if (s > ans) {
        ans = s;
        for (int i = 0 ; i < m ; ++ i) {
            ans_perm[cst[i][1]] = i;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> x[i];
    }
    for (int i = 0 ; i < n ; ++ i)
        cin >> p[i];
    ans = -1e15;
    fill(pre_msk, pre_msk + m + 1, 0);
    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j < m ; ++ j) {
        if (p[i][j] == '1')
            pre_msk[j] |= 1 << i;
    }
    for (int msk = 0 ; msk < (1 << n) ; ++ msk)
        brute(msk);

    for (int i = 0 ; i < m ; ++ i)
        cout << ans_perm[i] + 1 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (int i = 0 ; i < 1024 ; ++ i)
        pcnt[i] = __builtin_popcount(i);

    for (cin >> T ; T -- ; ) {
        solve();
    }
}