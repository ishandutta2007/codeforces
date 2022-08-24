#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int b;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> a >> b;
    for (int i = 0; (1LL * i * a) <= n; i++) {
        if ((n - a * i) % b == 0) {
            cout << "YES" << '\n';
            cout << i << " " << (n - a * i) / b;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}