#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int a, b;
        cin >> a >> b;
        if (a % 2 != b % 2) cout << -1 << endl;
        else if (a != b) cout << 2 << endl;
        else if (a == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}