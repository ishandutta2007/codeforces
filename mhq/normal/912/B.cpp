#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    long long t = 1;
    while (t < n) {
        t = 2 * t + 1;
    }
    if (k == 1) cout << n;
    else {
        cout << t;
    }
    return 0;
}