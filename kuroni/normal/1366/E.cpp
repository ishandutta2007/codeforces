#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MOD = 998244353;

int n, m, a[N], b[N];
long long ans = 1;
vector<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    if (a[st[0]] != b[1]) {
        return cout << 0, 0;
    }
    for (int i = 1, pt = 0; i <= m; i++) {
        while (pt < st.size() && a[st[pt]] < b[i]) {
            pt++;
        }
        if (pt == st.size() || a[st[pt]] != b[i]) {
            return cout << 0, 0;
        }
        if (i > 1) {
            (ans *= st[pt] - st[pt - 1]) %= MOD;
        }
    }
    cout << ans;
}