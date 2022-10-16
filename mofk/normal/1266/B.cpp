#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        long long n;
        cin >> n;
        if (n < 15) cout << "NO" << endl;
        else if (n % 14 >= 1 && n % 14 <= 6) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}