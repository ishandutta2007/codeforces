
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// force max = k, algorithm = 0
// N = 1111111111
// M = 1000000000

// N M
// k k|M
// 0 k

int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int M = (1 << 17);
    const int N = (1 << 18) - 1;
    cin >> k;
    cout << "3 2\n";
    cout << N << " " << M << '\n';
    cout << k << " " << (k | M) << '\n';
    cout << 0 << " " << k << '\n';
}