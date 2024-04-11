#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a;
        int sum = accumulate(A.begin(), A.end(), 0);
        bool ok = false;
        for (int i = 2; i * i <= sum; ++i) {
            if (sum % i == 0) ok = true;
        }
        int id = -1;
        if (!ok) {
            for (int i = 0; i < N; ++i) if (A[i] & 1) id = i;
        }
        vector<int> ans;
        for (int i = 0; i < N; ++i) if (i != id) ans.push_back(i);
        cout << int(ans.size()) << '\n';
        for (int i : ans) cout << i+1 << ' '; cout << '\n';
    }
}