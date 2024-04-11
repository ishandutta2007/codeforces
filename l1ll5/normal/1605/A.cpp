#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void work() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    LL tmp = a1 + a3 - 2 * a2;
    tmp %= 3;
    if (tmp == -2) {
        cout << "1\n";
    }
    if (tmp == -1) {
        cout << "1\n";
    }
    if (tmp == 0) {
        cout << "0\n";
    }
    if (tmp == 1) {
        cout << "1\n";
    }
    if (tmp == 2) {
        cout << "1\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        work();
    }
}