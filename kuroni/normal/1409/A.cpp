#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << (a == b ? 0 : (abs(a - b) - 1) / 10 + 1) << '\n';
    }
}