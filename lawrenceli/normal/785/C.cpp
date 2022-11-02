#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

int main() {
    cin >> n >> m;
    if (m >= n) {
        cout << n << endl;
        return 0;
    }
    
    ll lo = 0, hi = 2e9;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (mid * (mid + 1) / 2 >= n - m) hi = mid;
        else lo = mid + 1;
    }
    cout << lo + m << endl;
}