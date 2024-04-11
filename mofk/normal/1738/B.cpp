#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n + 1), s(n + 1);
        for (int i = n - k + 1; i <= n; ++i) cin >> s[i];
        for (int i = n - k + 2; i <= n; ++i) a[i] = s[i] - s[i-1];
        if (k > 1 && a[n - k + 2] * (n - k + 1) < s[n - k + 1]) cout << "No" << endl;
        else {
            int ok = 0;
            for (int i = n - k + 2; i < n; ++i) if (a[i] > a[i+1]) {
                ok = 1;
            }
            if (ok) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}