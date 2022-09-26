#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].first--;
            A[i].second = i;
        }
        sort(A.begin(), A.end());
        vector<int> best(N);
        set<int> st;
        st.insert(-1);
        st.insert(N);
        for (auto v : A) {
            int a, i; tie(a, i) = v;
            auto it = st.insert(i).first;
            int l = *prev(it);
            int r = *next(it);
            best[a] = max(best[a], r - l - 1);
        }
        vector<int> good(N+2);
        for (int a = 0; a < N; ++a) {
            int q = min(N-a, best[a]);
            if (q) good[q]++;
        }
        for (int i = N; i > 0; --i) {
            good[i] += good[i+1];
            // cout << "01"[good[i] == N-i+1];
        }
        for (int i = 1; i <= N; ++i) cout << "01"[good[i] == N-i+1];
        cout << '\n';
    }
}