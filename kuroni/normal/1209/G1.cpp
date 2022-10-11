#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, cur = 0, sum = 0, ans = 0, a[N], r[N], cnt[N];
set<int> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        r[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (se.find(a[i]) == se.end()) {
            se.insert(a[i]);
            sum += cnt[a[i]];
            cur = max(cur, cnt[a[i]]);
        }
        if (r[a[i]] == i) {
            se.erase(a[i]);
        }
        if (se.empty()) {
            ans += sum - cur;
            cur = sum = 0;
        }
    }
    cout << ans;
}