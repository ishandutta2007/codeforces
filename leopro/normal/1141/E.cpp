#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll H, n;
    cin >> H >> n;
    ll d[n];
    for (int i = 0; i < n; ++i) cin >> d[i];
    ll delta = 0;
    ll minimum = 0;
    for (int i = 0; i < n; ++i) {
        delta += d[i];
        if (minimum > delta) minimum = delta;
    }
    if (H + minimum > 0 && delta >= 0) {
        cout << "-1" << endl;
        return 0;
    }
    ll k;
    if (delta < 0) {
        ll p = H + minimum;
        p = (p < 0)? 0 : p;
        p = (p + (-delta - 1)) / (-delta);
        H = H + (p * delta);
        k = p * n;
    } else { k = 0; }
    for (int i = 0; i < n; ++i) {
        H += d[i];
        if (H <= 0) {
            cout << k + i + 1 << endl;
            return 0;
        }
    }
    return 0;
}