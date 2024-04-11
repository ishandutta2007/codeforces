#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m, 0);
        for (int i = 0; i < a.size(); ++i) cin >> a[i];
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) for (int j = 0; j < i; ++j) if (a[j] < a[i]) ++ans;
        cout << ans << '\n';
    }
    return 0;
}