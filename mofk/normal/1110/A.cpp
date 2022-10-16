#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int b, n, s = 0, x;
    cin >> b >> n;
    if (b & 1) {
        for (int i = 0; i < n; ++i) cin >> x, s += x;
    }
    else {
        for (int i = 0; i < n; ++i) cin >> s;
    }
    cout << ((s & 1) ? "odd" : "even") << endl;
    return 0;
}