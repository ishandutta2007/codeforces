#include <bits/stdc++.h>
using namespace std;
int a, b, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> k >> a >> b;
    if (a > b) swap(a, b);
    if (k > a && k > b) {
        cout << -1;
        return 0;
    }
    else if (k > a) {
        if (b % k != 0) cout << -1;
        else cout << (b / k);
    }
    else {
        cout << (a / k) + (b / k);
    }
    return 0;
}