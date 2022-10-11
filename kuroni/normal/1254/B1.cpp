#include <bits/stdc++.h>
using namespace std;
    
const int N = 1E6 + 5;
const long long INF = 1E18 + 7;
    
int n;
long long su, ans = INF, a[N], pre[N];
    
long long solve(long long p) {
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = pre[i] % p;
        ret += min(cur, p - cur);
    }
    return ret;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1] + a[i];
    }
    if ((su = pre[n]) == 1) {
        return cout << -1, 0;
    }
    for (int i = 2; i < N; i++) {
        if (su % i == 0) {
            ans = min(ans, solve(i));
            while (su % i == 0) {
                su /= i;
            }
        }
    }
    if (su > 1) {
        ans = min(ans, solve(su));
    }
    cout << ans;
}