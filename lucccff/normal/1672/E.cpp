#include <bits/stdc++.h>
using namespace std;

int a[2010];

int main() {
    int n, l, r, x;
    cin >> n;
    l = n;
    r = 2000 * n + 1;
    while (l < r) {
        int m = l + r >> 1;
        cout << "? " << m << endl << flush;
        cin >> x;
        if (x != 1) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    int s = r - n + 1, mn = r;
    for(int i = 2; i <= n; i++) {
        int t = (mn - 1) / i;
        while (t * i >= s + n - i) {
            cout << "? " << t << endl << flush;
            cin >> x;
            if (x > i || x == 0) break;
            else mn = x * t;
            t--;
        }
    }
    cout << "! " << mn << endl;
    return 0;
}