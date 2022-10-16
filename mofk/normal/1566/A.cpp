#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, s;
        cin >> n >> s;
        n -= (n - 1) / 2;
        cout << s / n << '\n';
    }
    return 0;
}