#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

using rain = pair<int, ll>;
#define x first
#define p second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<rain> r(n);
    for (auto &[x, p]: r) cin >> x >> p;
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) { return r[i].x < r[j].x; });
    auto leftPoint = [](rain r) { return r.x - r.p; };
    auto rightPoint = [](rain r) { return r.x + r.p; };
    auto byLeftPoint = [](rain a, rain b) { return pair{a.x - a.p, a.x} < pair{b.x - b.p, b.x}; };
    auto byRightPoint = [](rain a, rain b) { return pair{a.x + a.p, a.x} < pair{b.x + b.p, b.x}; };
    multiset<rain, decltype(byRightPoint)> left;
    multiset<rain, decltype(byLeftPoint)> right(r.begin(), r.end());
    ll leftSum = 0, rightSum = 0;
    int leftCnt = 0, rightCnt = 0;
    vector<ll> ans(n);
    for (int i: indices) {
        while (!right.empty() && leftPoint(*right.begin()) <= r[i].x) {
            auto r = *right.begin();
            right.erase(right.begin());
            rightSum += r.p - r.x;
            rightCnt++;
        }
        while (!left.empty() && rightPoint(*left.begin()) < r[i].x) {
            auto r = *left.begin();
            left.erase(left.begin());
            leftSum -= r.p + r.x;
            leftCnt--;
        }
        rightSum -= r[i].p - r[i].x;
        rightCnt--;
        leftSum += r[i].p + r[i].x;
        leftCnt++;
        ans[i] = (rightSum + rightCnt * 1LL * r[i].x + leftSum - leftCnt * 1LL * r[i].x);
        left.emplace(r[i].x, r[i].p);
    }
    multiset<rain, decltype(byRightPoint)> rightOverflows;
    for (int i = 0; i < n; ++i) if (ans[i] > m) rightOverflows.emplace(r[i].x, ans[i] - m);
    multiset<rain, decltype(byLeftPoint)> leftOverflows;
    vector<bool> overflows(n);
    for (int i: indices) {
        ll right = (!rightOverflows.empty() ? rightPoint(*--rightOverflows.end()) : (ll) -1e9);
        ll left = (!leftOverflows.empty() ? leftPoint(*leftOverflows.begin()) : (ll) 2e9);
        if (ans[i] > m) {
            rightOverflows.erase(rightOverflows.find(rain(r[i].x, ans[i] - m)));
            leftOverflows.emplace(r[i].x, ans[i] - m);
        }
        overflows[i] = right > r[i].x + r[i].p || left < r[i].x - r[i].p;
    }
    for (int i = 0; i < n; ++i) cout << !overflows[i];
    cout << '\n';
}