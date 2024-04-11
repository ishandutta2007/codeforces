#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, len, k, a[N];
long long ans = 0;

long long solve() {
    long long sle = 0, sri = 0, ans = 0;
    multiset<int> le, ri;
    for (int i = 0; i < len; i++) {
        ri.insert(a[i]);
        sri += a[i];
    }
    while (le.size() < k && !ri.empty()) {
        int u = *ri.begin();
        if (u > 0) {
            break;
        }
        sri -= u; sle += u;
        le.insert(u); ri.erase(ri.begin());
    }
    for (int i = len; i <= n; i++) {
        // erase a[i - len]
        if (le.find(a[i - len]) != le.end()) {
            le.erase(le.find(a[i - len]));
            sle -= a[i - len];
        } else {
            ri.erase(ri.find(a[i - len]));
            sri -= a[i - len];
        }
        // insert a[i]
        if (le.empty() || *prev(le.end()) <= a[i]) {
            ri.insert(a[i]);
            sri += a[i];
        } else {
            le.insert(a[i]);
            sle += a[i];
        }
        while (le.size() > k) {
            int u = *prev(le.end());
            sle -= u; sri += u;
            ri.insert(u); le.erase(prev(le.end()));
        }
        while (le.size() < k && !ri.empty()) {
            int u = *ri.begin();
            if (u > 0) {
                break;
            }
            sle += u; sri -= u;
            le.insert(u); ri.erase(ri.begin());
        }
        ans = max(ans, abs(sri - sle));
        // cout << i << ": " << sri - sle << '\n';
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            a[j] = -a[j];
        }
        ans = max(ans, solve());
    }
    cout << ans;
}