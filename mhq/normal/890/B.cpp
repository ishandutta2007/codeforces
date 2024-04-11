#include <bits/stdc++.h>
using namespace std;
int a[2 * (int)1e5 + 5];
int n;
int b[2 * (int)1e5 + 5];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = max(b[i], i);
    }
    int mi = 10000000;
    int ind = 0;
    for (int i = 0; i <= 2 * (int)1e5; i++) {
        if (b[i] == 0) continue;
        if (mi > b[i]) {
            mi = b[i];
            ind = i;
        }
    }
    cout << ind;
}