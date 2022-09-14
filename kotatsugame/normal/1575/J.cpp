#include <bits/stdc++.h>
using namespace std;
int _ = (cout << fixed << setprecision(9), cin.tie(0), ios::sync_with_stdio(0));
using Int = long long;
int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M));
    for (auto &row : A) for (auto &a : row) cin >> a;
    vector<int> C(K); for (auto &c : C) cin >> c, c--;
    vector<int> ans;
    for (int i = 0; i < K; i++) {
        int ci = 0, cj = C[i];
        while (ci < N) {
            if (A[ci][cj] == 1) {
                A[ci][cj] = 2;
                cj++;
            } else if (A[ci][cj] == 2) {
                ci++;
            } else if (A[ci][cj] == 3) {
                A[ci][cj] = 2;
                cj--;
            } else {
                exit(1);
            }
        }
        ans.push_back(cj);
    }
    for (int i = 0; i < K; i++) {
        cout << ans[i] + 1 << " \n"[i + 1 == K];
    }
    return 0;
}