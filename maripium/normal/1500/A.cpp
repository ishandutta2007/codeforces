#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    if (N > 6000) {
        N = 6000;
        A.resize(N);
    }

    const int V = 3e6;

    vector<pair<int, int>> P0(V, {-1, -1});
    vector<pair<int, int>> P1(V, {N, N});

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int v = A[j].first - A[i].first;
            P0[v] = max(P0[v], pair<int, int>(i, j));
            P1[v] = min(P1[v], pair<int, int>(j, i));
        }
    }

    for (int v = 0; v < V; ++v) {
        if (P0[v].first == -1) continue;
        if (P1[v].first == N) continue;
        if (P0[v].first <= P1[v].first) continue;
        auto [a, b] = P0[v];
        auto [c, d] = P1[v];

        // b - a = c - d

        cout << "YES\n";
        cout << A[a].second + 1 << ' ' << A[c].second + 1 << ' ' << A[b].second + 1 << ' ' << A[d].second + 1 << '\n';
        return 0;
    }

    cout << "NO\n";
}