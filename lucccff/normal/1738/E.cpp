#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 998244353;

long long a[N], n, b[N], pre[N];
long long jie[N], ijie[N], inv[N];

long long qp(long long n, int m) {
    long long k = n, t = 1;
    while (m) {
        if (m & 1) t = t * k % P;
        k = k * k % P;
        m >>= 1;
    }
    return t;
}

long long C(int n, int m) {
    return ijie[n - m] * ijie[m] % P * jie[n] % P;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    inv[1] = 1;
    jie[0] = jie[1] = 1;
    ijie[0] = ijie[1] = 1;
    for(int i = 2; i < N; i++) {
        inv[i] = inv[P % i] * (P - P / i) % P;
        ijie[i] = ijie[i - 1] * inv[i] % P;
        jie[i] = jie[i - 1] * i % P;
    }
    int t;
    cin >> t;
    while (t--) {
        long long ans = 1;
        cin >> n;
        pre[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int k = 0;
        for(int i = 1; i <= n; i++) {
            if (pre[i] * 2 == pre[n])  {
                k = i;
                break;
            }
        }
        int p = k;
        if (k) {
            k++;
            while(k <= n && a[k] == 0) k++;
            int x = k - p;
            if (p == 1 && a[1] == 0) x--;
            ans = qp(2, x);
            int l = 1, r = n;
            while(l < p && r > k) {
                if (pre[l] == pre[n] - pre[r - 1]) {
                    int x = l + 1;
                    while (a[x] == 0) x++;
                    int k1 = x - l;
                    l = x;
                    x = r - 1;
                    while (a[x] == 0) x--;
                    int k2 = r - x;
                    r = x;
                    long long cnt = 0;
                    for(int y = 0; y <= min(k1, k2); y++) {
                        cnt += C(k1, y) * C(k2, y) % P;
                    }
                    cnt %= P;
                    ans = ans * cnt % P;
                }
                else if (pre[l] > pre[n] - pre[r - 1]) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        else {
            int l = 1, r = n;
            while(l < r) {
                if (pre[l] == pre[n] - pre[r - 1]) {
                    int x = l + 1;
                    while (a[x] == 0) x++;
                    int k1 = x - l;
                    l = x;
                    x = r - 1;
                    while (a[x] == 0) x--;
                    int k2 = r - x;
                    r = x;
                    long long cnt = 0;
                    for(int y = 0; y <= min(k1, k2); y++) {
                        cnt += C(k1, y) * C(k2, y) % P;
                    }
                    cnt %= P;
                    ans = ans * cnt % P;
                }
                else if (pre[l] > pre[n] - pre[r - 1]) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}