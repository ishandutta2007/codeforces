#include <bits/stdc++.h>
using namespace std;
int n;
bool ok(int x) {
    int p = 1;
    while (x % 2 == 0) {
        x = x / 2;
        p = p * 2;
    }
    if (x == p * 2 - 1) return true;
    else return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int ma = -1;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (ok(i)) ma = i;
        }
    }
    cout << ma;
    return 0;
}