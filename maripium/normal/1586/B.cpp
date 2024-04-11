#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<bool> was(N);
        for (int i = 0; i < M; ++i) {
            int a, b, c; cin >> a >> b >> c;
            was[--b] = true;
        }
        int root = 0;
        while (was[root]) root++;
        for (int i = 0; i < N; ++i) if (i != root) {
            cout << i+1 << ' ' << root+1 << '\n';
        }
    }
}