#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        int sum = 0, mi = INT_MAX;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            mi = min(mi, x);
        }
        cout << sum - mi * n << endl;
    }
}