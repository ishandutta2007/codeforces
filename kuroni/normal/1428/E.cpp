#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, a;

struct carrot {
    int a, b;

    carrot(int _a, int _b) : a(_a), b(_b) {}

    long long value() const {
        int cnt = a / b, ov = a % b;
        return 1LL * cnt * cnt * (b - ov) + 1LL * (cnt + 1) * (cnt + 1) * ov;
    }

    long long next() const {
        return carrot(a, b).value() - carrot(a, b + 1).value();
    }

    bool operator<(const carrot& oth) const {
        return next() < oth.next();
    }
};
priority_queue<carrot> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pq.push(carrot(a, 1));
    }
    for (int i = n + 1; i <= k; i++) {
        auto u = pq.top(); pq.pop();
        pq.push({u.a, u.b + 1});
    }
    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top().value();
        pq.pop();
    }
    cout << ans;
}