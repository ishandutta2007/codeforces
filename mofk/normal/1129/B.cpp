#include <bits/stdc++.h>

using namespace std;

long long k;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    if (k < 999999) {
        cout << 2 << endl;
        cout << -1 << ' ' << k + 2 << endl;
        return 0;
    }
    long long b = 2000;
    long long a = (b - k % b) % b;
    while (a - (k + a) / b <= 0) a += b;
    long long x = a - (k + a) / b;
    cout << b << endl;
    for (int i = 0; i < b - 2; ++i) cout << 0 << ' ';
    cout << -x << ' ' << a << endl;
    return 0;
}