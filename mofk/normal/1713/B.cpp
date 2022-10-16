#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int l = 0;
        while (l + 1 < n && a[l] <= a[l+1]) ++l;
        while (l + 1 < n && a[l] >= a[l+1]) ++l;
        cout << (l == n - 1 ? "YES" : "NO") << '\n';
    }
    return 0;
}