#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1);

int main() {
    int n;
    cin >> n;
    int r[n];
    for(int i = 0; i < n; ++i)
            cin >> r[i];
    sort(r, r + n);
    reverse(r, r + n);
    double res = 0;
    for(int i = 0; i < n; i += 2) {
            double cur = r[i], prev = (i + 1 < n ? r[i + 1] : 0);
            res += pi * (cur * cur - prev * prev);
    }
    cout.setf(ios::fixed);
    cout << res;
    cin >> n;
    return 0;
}