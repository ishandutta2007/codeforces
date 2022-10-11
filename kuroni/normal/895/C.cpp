#include <bits/stdc++.h>
using namespace std;

const int N = 20, MX = 22, M = 1E5 + 5, MOD = 1E9 + 7;

int n, u, cnt[1 << N];
long long ans = 0, pw[M], cl[1 << N], cr[1 << N];
vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57, 59, 61, 67};
vector<int> le, ri;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i < M; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    for (int i = 1; i <= n; i++) {
        cin >> u;
        int cur = 0;
        for (int i = 0; i < (int)pr.size(); i++) {
            int p = pr[i];
            while (u % p == 0) {
                cur ^= (1 << i);
                u /= p;
            }
        }
        cnt[cur]++;
    }
    for (int i = 0; i < (1 << N); i++) {
        if (cnt[i] > 0) {
            if (le.size() < MX) {
                le.push_back(i);
            } else {
                ri.push_back(i);
            }
        }
    }
    for (int msk = 0; msk < (1 << le.size()); msk++) {
        int tmp = 0;
        long long cur = 1;
        for (int i = 0; i < le.size(); i++) {
            int u = le[i];
            if (msk >> i & 1) {
                tmp ^= u;
            }
            (cur *= pw[cnt[u] - 1]) %= MOD;
        }
        (cl[tmp] += cur) %= MOD;
    }
    for (int msk = 0; msk < (1 << ri.size()); msk++) {
        int tmp = 0;
        long long cur = 1;
        for (int i = 0; i < ri.size(); i++) {
            int u = ri[i];
            if (msk >> i & 1) {
                tmp ^= u;
            }
            (cur *= pw[cnt[u] - 1]) %= MOD;
        }
        (cr[tmp] += cur) %= MOD;
    }
    for (int i = 0; i < (1 << N); i++) {
        (ans += 1LL * cl[i] * cr[i]) %= MOD;
    }
    cout << (ans + MOD - 1) % MOD;
}