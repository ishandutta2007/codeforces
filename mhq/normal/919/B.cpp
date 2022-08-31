#include <bits/stdc++.h>
using namespace std;
bool ok(int s) {
    int sum = 0;
    while (s > 0) {
        sum += s % 10;
        s /= 10;
    }
    return (sum == 10);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int k;
    cin >> k;
    int cnt = 0;
    for (int i = 1; i <= 3 * (int)1e7; i++) {
        if (ok(i)) {
            cnt++;
            if (cnt == k) {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}