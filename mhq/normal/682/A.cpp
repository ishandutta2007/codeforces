#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    int t0 = n / 5;
    int t4 = (n + 1) / 5;
    int t3 = (n + 2) / 5;
    int t2 = (n + 3) / 5;
    int t1 = (n + 4) / 5;

    int q0 = m / 5;
    int q4 = (m + 1) / 5;
    int q3 = (m + 2) / 5;
    int q2 = (m + 3) / 5;
    int q1 = (m + 4) / 5;

    cout << 1ll * t0 * q0 + 1ll * t1 * q4 + 1ll * t2 * q3 + 1ll * t3 * q2 + 1ll * t4 * q1 << endl;

    return 0;
}