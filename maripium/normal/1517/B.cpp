#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        vector<tuple<int, int, int>> vals;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> A[i][j];
                vals.emplace_back(A[i][j], i, j);
            }
        }

        vector<vector<int>> ans(N, vector<int>(M, -1));
        sort(vals.begin(), vals.end());

        for (int z = 0; z < M; ++z) {
            auto [_, i, j] = vals[z];
            ans[i][z] = j;
        }

        for (int i = 0; i < N; ++i) {
            vector<char> was(M);
            for (int j = 0; j < M; ++j) if (ans[i][j] != -1) was[ans[i][j]] = true;
            int k = 0;
            for (int j = 0; j < M; ++j) if (!was[j]) {
                while (ans[i][k] != -1) k++;
                ans[i][k] = j;
                was[j] = true;
            }
            for (int j = 0; j < M; ++j) {
                cout << A[i][ans[i][j]] << " \n"[j+1 == M];
            }
        }
    }
}