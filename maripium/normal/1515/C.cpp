#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int N, M, X; cin >> N >> M >> X;
        priority_queue<pair<int64_t, int>> hp;
        for (int i = 0; i < M; ++i) hp.emplace(0, i);
        cout << "YES\n";
        for (int i = 0; i < N; ++i) {
            int h; cin >> h;
            auto [v, j] = hp.top();
            hp.pop();
            cout << j+1 << " \n"[i == N-1];
            hp.emplace(v-h, j);
        }
    }
}