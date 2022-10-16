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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<int> orda(n);
        iota(orda.begin(), orda.end(), 0);
        sort(orda.begin(), orda.end(), [&](int x, int y) { return a[x] < a[y]; });
        vector<int> ordb(n);
        iota(ordb.begin(), ordb.end(), 0);
        sort(ordb.begin(), ordb.end(), [&](int x, int y) { return b[x] < b[y]; });
        vector<int> pb(n);
        for (int i = 0; i < n; ++i) pb[ordb[i]] = i;
        int mn = n;
        for (int i = n - 1; i >= 0; --i) {
            mn = min(mn, pb[orda[i]]);
            if (mn == i) {
                break;
            }
        }
        string s;
        for (int i = 0; i < n; ++i) if (a[i] < a[orda[mn]]) s += '0'; else s += '1';
        cout << s << '\n';
    }
    return 0;
}