#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a;
        vector<int> deg(N);
        for (int i = 0; i < N-1; ++i) {
            int v, u; cin >> v >> u;
            deg[--v] ++;
            deg[--u] ++;
        }
        vector<int> tots; for (int v = 0; v < N; ++v) for (int i = 0; i < deg[v]-1; ++i) tots.emplace_back(A[v]);
        int64_t cur = accumulate(A.begin(), A.end(), int64_t(0));
        cout << cur;
        sort(tots.rbegin(), tots.rend());
        for (int a : tots) {
            cout << ' ' << (cur += a);
        }
        cout << '\n';
    }
}