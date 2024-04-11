#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        []() {
        int N; cin >> N;
        vector<vector<int>> A(N);
        vector<int> As;
        for (int i = 0; i < N; ++i) {
            int sz; cin >> sz;
            A[i].resize(sz);
            for (int &a : A[i]) {
                cin >> a;
                As.emplace_back(a);
            }
        }
        sort(As.begin(), As.end());
        As.resize(unique(As.begin(), As.end()) - As.begin());
        for (auto &v : A) for (int& a : v) a = lower_bound(As.begin(), As.end(), a) - As.begin();
        const int B = 400;
        int M = As.size(); vector<int> ok(M);
        for (int i = 0; i < N; ++i) if (A[i].size() > B) {
            for (int v : A[i]) ok[v] = 1;
            for (int j = 0; j < N; ++j) if (i != j) {
                int cnt = 0;
                for (int v : A[j]) cnt += ok[v];
                if (cnt >= 2) {
                    cout << i+1 << ' ' << j+1 << '\n';
                    return;
                }
            }
            for (int v : A[i]) ok[v] = 0;
        }
        vector<vector<int>> locs(M);
        fill(ok.begin(), ok.end(), -1);
        for (int i = 0; i < N; ++i) if (A[i].size() <= B) for (int v : A[i]) locs[v].emplace_back(i);
        for (int v = 0; v < M; ++v) {
            for (int i : locs[v]) {
                for (int v2 : A[i]) if (v2 != v) {
                    if (ok[v2] != -1) {
                        cout << i+1 << ' ' << ok[v2]+1 << '\n';
                        return;
                    } else ok[v2] = i;
                }
            }
            for (int i : locs[v]) for (int v2 : A[i]) ok[v2] = -1;
        }
        cout << "-1\n";
        }();
    }
}