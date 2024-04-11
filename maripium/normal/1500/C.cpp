#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> B(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            --A[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
            --B[i][j];
        }
    }

    vector<int> perm(N);

    map<vector<int>, vector<int>> MB;

    for (int i = 0; i < N; ++i) MB[B[i]].emplace_back(i);

    for (int i = N-1; i >= 0; --i) {
        if (MB[A[i]].empty()) {
            cout << "-1\n";
            return 0;
        }
        perm[i] = MB[A[i]].back();
        MB[A[i]].pop_back();
    }
    vector<int> invp(N);
    for (int i = 0; i < N; ++i) invp[perm[i]] = i;

    vector<int> ops;

    vector<bool> done(N-1);

    vector<vector<int>> badmoves(N-1);
    vector<int> numbad(M);

    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M; ++j) {
            if (B[i][j] > B[i+1][j]) {
                badmoves[i].emplace_back(j);
                numbad[j] ++;
            }
        }
    }

    queue<int> bfs;

    for (int i = 0; i < M; ++i) if (!numbad[i]) bfs.emplace(i);

    while (!bfs.empty()) {
        int c = bfs.front(); bfs.pop();
        ops.emplace_back(c);
        for (int i = 0; i < N-1; ++i) if (!done[i] && B[i][c] < B[i+1][c]) {
            done[i] = true;
            for (int j : badmoves[i]) {
                if (--numbad[j] == 0) bfs.emplace(j);
            }
        }
    }

    for (int i = 0; i < N-1; ++i) if (!done[i] && invp[i] > invp[i+1]) {
        cout << "-1\n";
        return 0;
    }
    reverse(ops.begin(), ops.end());

    cout << int(ops.size()) << '\n';
    for (int c : ops) {
        cout << c+1 << ' ';
    }
    return 0;
}