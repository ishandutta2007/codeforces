#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n, u, cnt[N];
long long ans = 0;

struct dsu {
    int dsu[N];

    void init() {
        fill(dsu, dsu + N, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
    }

    int connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return 0;
        }
        if (dsu[u] > dsu[v]) {
            swap(u, v);
        }
        int ans = (dsu[u] == -1 ? cnt[u] : 1) + (dsu[v] == -1 ? cnt[v] : 1) - 1;
        dsu[u] += dsu[v];
        dsu[v] = u;
        return ans;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        cnt[u]++;
        ans -= u;
    }
    cnt[0]++;
    dsu.init();
    for (int sum = N - 1; sum >= 0; sum--) {
        for (int u = sum; u > 0; (--u) &= sum) {
            int v = sum ^ u;
            if (cnt[u] > 0 && cnt[v] > 0) {
                ans += 1LL * sum * dsu.connect(u, v);
            }
        }
    }
    cout << ans;
}