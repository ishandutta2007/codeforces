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
        cout << (a > 1) + (b > 1) << endl;
    }
    return 0;
}