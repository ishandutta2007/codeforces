#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0) cout << a;
        else if (n % 3 == 1) cout << b;
        else cout << (a ^ b);
        cout << '\n';
    }
    return 0;
}