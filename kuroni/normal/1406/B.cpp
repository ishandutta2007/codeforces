#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<int> neg, pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        neg.clear(); pos.clear();
        while (n--) {
            cin >> u;
            (u <= 0 ? neg : pos).push_back(u);
        }
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        long long ans = LLONG_MIN;
        for (int i = 0; i <= 5; i++) {
            int j = 5 - i;
            if (i > neg.size() || j > pos.size()) {
                continue;
            }
            long long cur = 1;
            if (i & 1) {
                for (int k = 1; k <= i; k++) {
                    cur *= neg[neg.size() - k];
                }
                for (int k = 0; k < j; k++) {
                    cur *= pos[k];
                }
            } else {
                for (int k = 0; k < i; k++) {
                    cur *= neg[k];
                }
                for (int k = 1; k <= j; k++) {
                    cur *= pos[pos.size() - k];
                }
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}