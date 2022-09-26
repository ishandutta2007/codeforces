#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a;
        set<int> st;
        for (int i = 0; i < N; ++i) for (int j = i+1; j < N; ++j) st.insert(A[j] - A[i]);
        cout << int(st.size()) << '\n';
    }
    return 0;
}