#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int u = 0, v = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        u |= x;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v |= x;
    }
    cout << u + v << endl;
}