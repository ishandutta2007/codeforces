#include <bits/stdc++.h>

using namespace std;

int n, m, nq;
int w[12];
int sum[1<<12];
int dist[1<<12][1<<12];
int cnt[1<<12];
vector <int> query[1<<12][101];
vector <int> up[1<<12][101];
int res[500005];

int con(string s) {
    int val = 0;
    for (int i = 0; i < n; ++i) val = val * 2 + s[i] - '0';
    return val;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> nq;
    for (int i = 0; i < n; ++i) cin >> w[n - 1 - i];
    for (int p = 0; p < (1 << n); ++p) for (int i = 0; i < n; ++i) if (p >> i & 1) sum[p] += w[i];
    for (int p = 0; p < (1 << n); ++p) for (int q = 0; q < (1 << n); ++q) {
        dist[p][q] = sum[(1 << n) - 1] - sum[p ^ q];
        if (dist[p][q] <= 100) up[p][dist[p][q]].push_back(q);
    }
    for (int j = 1; j <= m; ++j) {
        string s;
        cin >> s;
        ++cnt[con(s)];
    }
    for (int j = 1; j <= nq; ++j) {
        string s; int k;
        cin >> s >> k;
        query[con(s)][k].push_back(j);
    }
    for (int p = 0; p < (1 << n); ++p) {
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            for (auto q: up[p][i]) ans += cnt[q];
            for (auto q: query[p][i]) res[q] = ans;
        }
    }
    for (int i = 1; i <= nq; ++i) cout << res[i] << '\n';
    return 0;
}