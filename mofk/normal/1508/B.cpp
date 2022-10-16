#include <bits/stdc++.h>

using namespace std;

int msb(long long x) {
    int ans = 0;
    while (x) ++ans, x >>= 1;
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        long long k;
        cin >> n >> k; --k;

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(k & 1);
            k >>= 1;
        }
        reverse(ans.begin(), ans.end());
        if (k || ans[0]) {
            cout << -1 << endl;
            continue;
        }
        vector<int> pr;
        int last = 0;
        for (int i = 1; i <= n; ++i) if (i == n || !ans[i]) {
            for (int j = i - 1; j >= last; --j) pr.push_back(j + 1);
            last = i;
        }
        for (int i = 0; i < n; ++i) cout << pr[i] << ' ';
        cout << endl;
    }
    return 0;
}