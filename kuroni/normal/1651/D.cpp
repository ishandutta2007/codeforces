#include <bits/stdc++.h>
using namespace std;

const int MX = 2E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n), y(n), ax(n), ay(n);
    vector<int> ind(n), ptr(MX);
    vector<vector<int>> in(MX);
    vector<vector<pair<int, int>>> range(MX);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ind[i] = i;
        in[x[i]].push_back(y[i]);
    }
    for (int i = 0; i < MX; i++) {
        sort(in[i].begin(), in[i].end());
        int cur = -1;
        for (int v : in[i]) {
            if (v == cur + 1) {
                range[i].back().second++;
            } else {
                range[i].push_back({v, v});
            }
            cur = v;
        }
        range[i].push_back({MX + 1, MX + 1});
    }
    sort(ind.begin(), ind.end(), [&](const int u, const int v) {
        return y[u] < y[v];
    });
    for (int v : ind) {
        int ans = MX;
        for (int i = 0; i < ans; i++) {
            for (int j = -1; j <= 1; j += 2) {
                int cx = x[v] + i * j;
                while (ptr[cx] + 1 < range[cx].size() && range[cx][ptr[cx] + 1].first <= y[v]) {
                    ptr[cx]++;
                }
                if (range[cx][ptr[cx]].first <= y[v] && range[cx][ptr[cx]].second >= y[v]) {
                    auto [yl, yr] = range[cx][ptr[cx]];
                    yl--; yr++;
                    if (i + abs(y[v] - yl) < ans) {
                        ans = i + abs(y[v] - yl);
                        ax[v] = cx; ay[v] = yl;
                    }
                    if (i + abs(y[v] - yr) < ans) {
                        ans = i + abs(y[v] - yr);
                        ax[v] = cx; ay[v] = yr;
                    }
                } else {
                    ans = i;
                    ax[v] = cx; ay[v] = y[v];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ax[i] << " " << ay[i] << '\n';
    }
}