#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for (int &a : A) cin >> a;
    int row = N-1;
    vector<pair<int, int>> ans;
    vector<pair<int, int>> st;
    int row3 = -1, col3 = -1;
    for (int col = N-1; col >= 0; --col) {
        if (A[col] == 0) {
        } else if (A[col] == 1) {
            ans.emplace_back(row, col);
            st.emplace_back(row, col);
            row--;
        } else if (A[col] == 2) {
            if (st.empty()) {
                cout << "-1\n";
                return 0;
            }
            int nrow = st.back().first;
            int ncol = st.back().second;
            ans.emplace_back(nrow, col);
            st.pop_back();
            if (row3 == -1) {
                row3 = nrow;
                col3 = col;
            }
        } else {
            if (row3 == -1) {
                if (st.empty()) {
                    cout << "-1\n";
                    return 0;
                }
                tie(row3, col3) = st.back(); st.pop_back();
            }
            ans.emplace_back(row, col);
            ans.emplace_back(row, col3);
            tie(row3, col3) = make_pair(row, col);
            row--;
        }
    }
    cout << int(ans.size()) << '\n';
    for (auto p : ans) {
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}