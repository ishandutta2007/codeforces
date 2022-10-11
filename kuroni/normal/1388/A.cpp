#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, u, a = 6, b = 10, c = 14;
    cin >> n;
    while (n--) {
        cin >> u;
        if (a + b + c >= u) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int tmp = u - a - b - c;
            cout << a << " " << b << " ";
            if (tmp == a || tmp == b || tmp == c) {
                cout << c + 1 << " " << tmp - 1 << '\n';
            } else {
                cout << tmp << " " << c << '\n';
            }
        }
    }
}