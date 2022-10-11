#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, u, a[N];
long long ans = 0;

struct bit {
    long long bit[N];

    void update(int u, long long v) {
        for (; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }

    long long query(int u) {
        long long ret = 0;
        for (; u > 0; u -= u & -u) {
            ret += bit[u];
        }
        return ret;
    }

    int binary_search(long long v) {
        int pos = 0;
        for (int i = __lg(N); i >= 0; i--) {
            if (pos + (1 << i) <= n && bit[pos + (1 << i)] < v) {
                pos += (1 << i);
                v -= bit[pos];
            }
        }
        return pos + 1;
    }
} pos, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        a[u] = i;
    }
    for (int i = 1; i <= n; i++) {
        ans += i - 1 - pos.query(a[i]);
        pos.update(a[i], 1); sum.update(a[i], a[i]);
        int mid = pos.binary_search((i + 1) / 2), cnt = i / 2;
        long long cur = ans;
        cur += 1LL * (2 * mid - cnt + 1 - i % 2 * 2) * cnt / 2 - sum.query(mid - i % 2);
        cur += sum.query(n) - sum.query(mid) - 1LL * (2 * mid + cnt + 1) * cnt / 2;
        cout << cur << " ";
    }
}