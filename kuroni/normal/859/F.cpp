#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, pt = 1;
deque<int> opt = {0};
long long c, dem = 0, sup = 0, a[N], b[N], ans[N], sum[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> b[i] >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dem += a[i] + b[i];
        sum[i] = sum[i - 1];
        while (dem > c) {
            ans[i] = max(ans[i], c - sup);
            dem -= a[pt] + b[pt + 1];
            sup -= ans[pt];
            pt++;
        }
        while (!opt.empty() && opt.front() < pt - 1) {
            opt.pop_front();
        }
        if (!opt.empty()) {
            int u = opt.front();
            ans[i] = max(ans[i], a[i] + sum[i] - sum[u]);
        }
        sum[i] = sum[i - 1] + b[i + 1] + a[i] - ans[i];
        while (!opt.empty() && sum[opt.back()] >= sum[i]) {
            opt.pop_back();
        }
        opt.push_back(i);
        sup += ans[i];
    }
    cout << accumulate(ans + 1, ans + n + 1, 0LL);
}