#include <bits/stdc++.h>

using namespace std;

struct FT {
    vector<int> s;
    FT(int sz) : s(sz) {}
    void add(int p) {
        for (++p; p < s.size(); p += p & -p)
            s[p] += 1;
    }
    int query(int p) {
        int r = 0;
        for (++p; p > 0; p -= p & -p)
            r += s[p];
        return r;
    }
};

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++)
        A[i] += A[i - 1];
    for (int i = 0; i < N; i++)
        if (A[i] < 0)
            return cout << -1 << '\n', 0;

    if (A[N-1] != *max_element(A.begin(), A.end()))
        return cout << -1 << '\n', 0;

    auto u = A;
    sort(u.begin(), u.end());
    for (int64_t &x: A) x = lower_bound(u.begin(), u.end(), x) - u.begin();
    reverse(A.begin(), A.end());
    int64_t ans = 0;

    FT BIT(u.size() + 25);
    for (int x: A) {
        ans += BIT.query(x-1);
        BIT.add(x);
    }
    cout << ans << '\n';
}