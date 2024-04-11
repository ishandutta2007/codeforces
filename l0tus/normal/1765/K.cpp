#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    long long sum = 0, mn = 1e10;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        long long x; cin >> x;
        sum += x;
        if ((i + j) == n + 1) mn = min(mn, x);
    }
    cout << sum - mn;
}