#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            --A[i][j];
        }
    }


    vector<vector<vector<int>>> nxt_rows(N, vector<vector<int>>(N));
    vector<vector<vector<int>>> nxt_cols(N, vector<vector<int>>(N));

    for (int c = 0; c < N; ++c) {
        vector<int> cur;

        for (int i = N-1; i >= 0; --i) {
            for (int j = 0; j < int(cur.size()); ++j) if (A[cur[j]][c] == A[i][c]) {
                cur.erase(cur.begin() + j);
                break;
            }
            cur.insert(cur.begin(), i);
            if (cur.size() == Q+2) cur.pop_back();

            nxt_rows[i][c] = cur;
        }
    }

    for (int r = 0; r < N; ++r) {
        vector<int> cur;

        for (int i = N-1; i >= 0; --i) {
            for (int j = 0; j < int(cur.size()); ++j) if (A[r][cur[j]] == A[r][i]) {
                cur.erase(cur.begin() + j);
                break;
            }
            cur.insert(cur.begin(), i);
            if (cur.size() == Q+2) cur.pop_back();
            nxt_cols[r][i] = cur;
        }
    }

    vector<int> freq(N * N);
    int num_color = 0;
    vector<vector<bool>> active(N, vector<bool>(N));

    vector<int> ans(N);

    auto add_cell = [&](int x, int y) {
        if (active[x][y]) return;
        if (++freq[A[x][y]] == 1) {
            num_color ++;
        }
        active[x][y] = true;
    };

    auto remove_cell = [&](int x, int y) {
        if (!active[x][y]) return;
        if (--freq[A[x][y]] == 0) {
            num_color --;
        }
        active[x][y] = false;
    };

    for (int diff = -N+1; diff <= N-1; ++diff) {
        int li = N-1;
        while (true) {
            int lj = li + diff;
            if (0 <= lj && lj < N) break;
            --li;
        }
        int lj = li + diff;
        int ri = li;
        int rj = lj;

        vector<vector<pair<int, int>>> remove_at(N);
        while (li >= 0 && lj >= 0) {
            // cerr << "At " << li << ' ' << lj << '\n';

            for (int i : nxt_rows[li][lj]) {
                if (i <= ri) {
                    add_cell(i, lj);
                    remove_at[i].emplace_back(i, lj);
                }
            }
            for (int j : nxt_cols[li][lj]) {
                if (j <= rj) {
                    add_cell(li, j);
                    remove_at[li + (j - lj)].emplace_back(li, j);
                }
            }

            while (num_color > Q) {
                for (auto [i, j] : remove_at[ri]) {
                    remove_cell(i, j);
                }
                ri--;
                rj--;
            }

       //     cerr << "LIMIT " << li << ' ' << lj << ' ' << ri << ' ' << rj << '\n';
            ans[ri-li] ++;
            li--;
            lj--;
        }

        for (int i = li+1; i <= ri; ++i) {
            for (auto [_i, j] : remove_at[i]) remove_cell(_i, j);
        }
    }

    for (int i = N-2; i >= 0; --i) ans[i] += ans[i+1];

    for (int v : ans) cout << v << '\n';
}