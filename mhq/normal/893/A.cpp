#include <bits/stdc++.h>
using namespace std;
int n;
int pl1 = 1;
int pl2 = 2;
int x;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x != pl1 && x != pl2) {
            cout << "NO";
            return 0;
        }
        else {
            pl1 = 6 - pl1 - pl2;
            pl2 = x;
        }
    }
    cout << "YES";
    return 0;
}