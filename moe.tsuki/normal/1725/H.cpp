#include <bits/stdc++.h>

using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int &x: a) cin >> x;

    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        if (a[i] % 3 == 0) {
            A.push_back(i);
        } else {
            B.push_back(i);
        }
    }

    vector<int> ans(N);
    int half = N/2;
    if (A.size() >= B.size()) {
        for (int i = half; i < A.size(); i++)
            B.push_back(A[i]);
        for (int i = 0; i < half; i++)
            ans[A[i]] = 0;
        for (int i = 0; i < half; i++)
            ans[B[i]] = 1;

        cout << 2 << '\n';
        for (int i = 0; i < N; i++) {
            cout << ans[i];
        }
        cout << '\n';
    } else {
        for (int i = half; i < B.size(); i++)
            A.push_back(B[i]);

        for (int i = 0; i < half; i++)
            ans[A[i]] = 0;
        for (int i = 0; i < half; i++)
            ans[B[i]] = 1;

        cout << 0 << '\n';
        for (int i = 0; i < N; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
}