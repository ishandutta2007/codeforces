#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, int> ans = {-1, 0};
    for (int i = 0, cnt = 0, pt = 0; i < n; i++) {
        for (; pt < n && cnt <= k; pt++) {
            cnt += (a[pt] == 0);
        }
        if (cnt > k) {
            pt--; cnt--;
        }
        ans = max(ans, {pt - i, i});
        cnt -= (a[i] == 0);
    }
    cout << ans.first << '\n';
    for (int i = 0; i < ans.first; i++) {
        a[ans.second + i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}