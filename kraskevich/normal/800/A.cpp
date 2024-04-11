#include <bits/stdc++.h>

using namespace std;

using ld = long double;

const int N = 200 * 1000 + 10;
const ld eps = 1e-13;

int a[N];
int b[N];
ld p;
int n;

bool check(ld x) {
    if (x < eps)
        return true;
    ld s = 0;
    for (int i = 0; i < n; i++)
        s += max((ld)0, (x * a[i] - b[i]) / p);
    return s <= x + eps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ld low = 0;
    ld high = 1e16;
    if (check(high)) {
        cout << -1 << endl;
        return 0;
    }
    for (int rep = 0; rep < 200; rep++) {
        ld mid = (low + high) / 2;
        if (check(mid))
            low = mid;
        else
            high = mid;
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << low << endl;
}