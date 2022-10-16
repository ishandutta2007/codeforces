#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n + 1; ++i) cout << i << ' ';
        cout << endl;
    }
    return 0;
}