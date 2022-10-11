#include <bits/stdc++.h>
using namespace std;

const int MX = 1 << 17;

int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    if (k == 0) {
        cout << "1 1\n0\n";
    } else {
        cout << "3 3\n";
        cout << (k ^ MX) << " " << MX << " 0\n";
        cout << k << " " << (k ^ MX) << " 0\n";
        cout << "0 " << k << " " << k << '\n';
    }
}