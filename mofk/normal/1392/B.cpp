#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        long long k;
        cin >> n >> k; --k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long mx = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; ++i) a[i] = mx - a[i];
        mx = *max_element(a.begin(), a.end());
        if (k & 1) for (int i = 0; i < n; ++i) a[i] = mx - a[i];
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}