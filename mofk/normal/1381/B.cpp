#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) cin >> a[i];
        int mx = 0;
        vector<int> items;
        for (int i = 1; i < 2 * n; ++i) if (a[mx] < a[i]) {
            items.push_back(i - mx);
            mx = i;
        }
        items.push_back(2 * n - mx);
        bitset<2002> bs;
        bs.set(0);
        for (auto x: items) bs = bs | (bs << x);
        cout << (bs.test(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}