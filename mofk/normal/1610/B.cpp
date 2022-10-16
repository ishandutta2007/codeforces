#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> a) {
    int n = a.size();
    int l = 0, r = n - 1, x = -1;
    while (l < r) {
        if (a[l] == a[r]) {
            ++l;
            --r;
        }
        else if (x == -1) {
            x = a[l];
            ++l;
        }
        else {
            if (x == a[l]) ++l;
            else if (x == a[r]) --r;
            else return false;
        }
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> b = a;
        reverse(b.begin(), b.end());
        if (ok(a) || ok(b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}