#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, a[N];
long long le = 0, ri = 0, ans = 0;
map<int, int> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ma[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (ma[a[i]] >= k) {
            return cout << 0, 0;
        }
    }
    for (int i = 1; i <= n / 2; i++) {
        ans += a[n + 1 - i] - a[i];
    }
    ans -= (n - k);
    int cl = 0, cr = 0;
    for (int i = 1; i < k; i++) {
        if (a[i] < a[k]) {
            cl++;
            le += a[i];
        }
        if (a[n + 1 - i] > a[n + 1 - k]) {
            cr++;
            ri += a[n + 1 - i];
        }
    }
    ans = min(ans, 1LL * a[k] * cl - le - (cl - (k - ma[a[k]])));
    ans = min(ans, ri - 1LL * a[n + 1 - k] * cr - (cr - (k - ma[a[n + 1 - k]])));
    cout << ans;
}