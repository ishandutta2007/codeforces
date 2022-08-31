#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int z = 30; z >= 0; z--) {
            if (n >= (1 << z)) {
                cout << (1 << z) - 1 << '\n';
                break;
            }
        }
    }
    return 0;
}