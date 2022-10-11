#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int ask(int u) {
    cout << "? " << 200 / (1 << u) * 200 << endl;
    for (int i = (1 << u); i <= 200; i += (1 << u)) {
        for (int j = 1; j <= 200; j++) {
            cout << i << " " << j << " ";
        }
    }
    cout << endl;
    int x; cin >> x; return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l = 1, r = 7;
    int h, a;
    while (l <= r) {
        int m = (l + r) / 2;
        int x = ask(m);
        if (x > 0) {
            h = x;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    a = ask(0);
    int w = a / h;
    cout << "! " << 2 * (w + h) - 4 << endl;
}