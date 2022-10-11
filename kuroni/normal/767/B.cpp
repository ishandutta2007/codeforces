#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;
const long long INF = 1E18 + 7;

int n;
long long s, f, t, a[N];
pair<long long, long long> ans = {INF, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> f >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            long long cur = min(s, a[i] - 1);
            if (s + t <= f) {
                ans = min(ans, {s - cur, cur});
            }
        }
        s = max(s, a[i]) + t;
    }
    if (s + t <= f) {
        ans = min(ans, {0, s});
    }
    cout << ans.second;
}