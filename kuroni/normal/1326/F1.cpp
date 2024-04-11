#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n;
long long ans[1 << N], dp[N][1 << (N / 2)], sum[2][1 << (N / 2)];
char s[N][N];

void solve(int ch) {
    vector<int> le, ri;
    for (int i = 0; i < n; i++) {
        if (ch >> i & 1) {
            le.push_back(i);
        } else {
            ri.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        fill(dp[i], dp[i] + (1 << (n / 2)), 0);
    }
    do {
        int cur = 0;
        for (int i = 1; i < (int)le.size(); i++) {
            (cur <<= 1) ^= (s[le[i - 1]][le[i]] - '0');
        }
        dp[le.back()][cur]++;
    } while (next_permutation(le.begin(), le.end()));
    do {
        int cur = 0;
        for (int i = 1; i < (int)ri.size(); i++) {
            (cur <<= 1) ^= (s[ri[i - 1]][ri[i]] - '0');
        }
        dp[ri.front()][cur]++;
    } while (next_permutation(ri.begin(), ri.end()));
    int ls = le.size() - 1, rs = ri.size() - 1;
    for (int &u : le) {
        for (int &v : ri) {
            int mid = s[u][v] - '0';
            for (int lm = 0; lm < (1 << ls); lm++) {
                for (int rm = 0; rm < (1 << rs); rm++) {
                    ans[(((lm << 1) ^ mid) << rs) ^ rm] += dp[u][lm] * dp[v][rm];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int msk = 0; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == n / 2) {
            solve(msk);
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++) {
        cout << ans[i] << ' ';
    }
}