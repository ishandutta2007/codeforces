#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> x;
        int flg = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > x) a[i] = 1;
            else if (a[i] == x) a[i] = 1, flg = 1;
            else a[i] = -1;
        }
        if (!flg) {
            cout << "no" << '\n';
            continue;
        }
        if (n == 1) {
            if (a[1] > 0) cout << "yes" << '\n';
            else cout << "no" << '\n';
            continue;
        }
        flg = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > 0 && a[i+1] > 0) flg = 1;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > 0 && a[i+2] > 0) flg = 1;
        }
        if (flg) {
            cout << "yes" << '\n';
            continue;
        }
        cout << "no" << '\n';
    }
    return 0;
}