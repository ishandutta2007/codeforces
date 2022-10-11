#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int t;
long long a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a;
        cout << (a % 14 >= 1 && a % 14 <= 6 && a >= 14 ? "YES\n" : "NO\n");
    }
}