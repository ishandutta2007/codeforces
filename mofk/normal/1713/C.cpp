#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> p(n);
        int r = n - 1;
        while (r >= 0) {
            int t = sqrt(r - 1) + 1;
            t *= t;
            for (int l = t - r; l <= r; ++l) p[l] = t - l;
            r = t - r - 1;
        }
        for (int i = 0; i < n; ++i) cout << p[i] << ' ';
        cout << '\n';
    }
    return 0;
}