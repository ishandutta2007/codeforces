#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int n, k;

int main() {
    ios :: sync_with_stdio(false);

    cin >> n >> k;

    if (k == 1 && n > 1 || k > n) {
        cout << -1; return 0;
    } else if (n == 1) {
        cout << 'a'; return 0;
    }

    for (int i=0; i<n-k+2; i++) {
        if (i & 1) cout << 'b';
        else cout << 'a';
    }

    for (int i=2; i<k; i++) cout << char('a' + i);

    return 0;
}