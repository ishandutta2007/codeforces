#include <bits/stdc++.h>
using namespace std;

const int N = 200005, INF = 1E9 + 7;

int n, t, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        vector<int> st;
        for (int i = n; i >= 1; i--) {
            int cur = a[i];
            while (!st.empty() && st.back() <= a[i]) {
                cur = min(cur, st.back());
                st.pop_back();
            }
            ans += a[i] - cur;
            st.push_back(a[i]);
        }
        cout << ans << '\n';
    }
}