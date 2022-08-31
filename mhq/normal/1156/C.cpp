#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
ll x[maxN];
int n, z;
int l[maxN];
int add[maxN];
bool can(int len) {
    memset(add, 0, sizeof add);
    for (int j = 1; j <= len; j++) {
        add[max(len + 1, l[j])]++;
    }
    for (int j = len + 1; j <= n; j++) add[j] += add[j - 1];
    if (2 * len > n) return false;
    for (int j = 1; j <= len; j++) {
        if (add[n - j + 1] < (len - j + 1)) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> z;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    x[n + 1] = 2 * (int)1e9 + 100;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(x + 1, x + n + 1 + 1, x[i] + z) - x;
        l[i] = it;
    }
    int le = 0;
    int ri = n;
    while (ri - le > 1) {
        int mid = (le + ri) / 2;
        if (can(mid)) le = mid;
        else ri = mid;
    }
    cout << le;
    return 0;
}