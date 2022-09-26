#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> A(N); for (auto &a : A) cin >> a;
    vector<int> B(N, 1);
    auto value = [&](int A, int B) -> int64_t {
        int low = A/B;
        int nhigh = A%B;
        return int64_t(low) * low * (B-nhigh) + int64_t(low+1)*(low+1)*nhigh;
    };
    auto profit = [&](int A, int B) -> int64_t {
        assert(B < A);
        return value(A, B+1) - value(A, B);
    };
    using pq_t = pair<int64_t, int>;
    priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq;
    for (int i = 0; i < N; ++i) if (B[i] < A[i]) pq.emplace(profit(A[i], B[i]), i);
    int64_t ans = 0;
    for (int i = 0; i < N; ++i) ans += int64_t(A[i]) * A[i];
    for (int z = 0; z < K-N; ++z) {
        auto i = pq.top().second; pq.pop();
        ans += profit(A[i], B[i]);
        if (++B[i] < A[i]) {
            pq.emplace(profit(A[i], B[i]), i);
        }
    }
    cout << ans << '\n';
    return 0;
}