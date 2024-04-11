#include <bits/stdc++.h>

using namespace std;
long long t, n, a, b, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t >> n >> a >> b >> k;
    long long nb = n / 2, na = n - nb;
    if (a < b) {
        swap(a, b);
        swap(na, nb);
    }
    long long d = a - b;
    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    if (k == n) {
        cout << min(t, b) << endl;
        return 0;
    }
    if (k <= na) {
        cout << min(t, (a * na + b * nb) / k) << endl;
        return 0;
    }
    long long pb = b * nb / (k - na);
    if (pb < a) cout << min(t, pb) << endl;
    else cout << min(t, (a * na + b * nb) / k) << endl;
    return 0;
}