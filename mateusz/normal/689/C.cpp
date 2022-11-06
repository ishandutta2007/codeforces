#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

long long m;

int main() {

    cin >> m;

    long long low = 0;
    long long high = 1e18;
    long long res = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long ans = 0;
        for (long long k = 2; k <= 1000000; k++) {
            long long s = k * k * k;
            ans += mid / s;
            if (ans > m) {
                break;
            }
        }
        if (ans == m) {
            if (res == -1) {
                res = mid;
            } else {
                res = min(res, mid);
            }
        }
        if (ans >= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}