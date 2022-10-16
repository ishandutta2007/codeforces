#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    int f = 1;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2 == 0) cout << x / 2 << '\n';
        else {
            cout << (x + f) / 2 << '\n';
            f = -f;
        }
    }
    return 0;
}