#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        int s = 0, x;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x, s += x;
        cout << (s % n != 0) << endl;
    }
    return 0;
}