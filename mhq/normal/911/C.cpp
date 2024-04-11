#include <bits/stdc++.h>
using namespace std;
int k1, k2, k3;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> k1 >> k2 >> k3;
    if (k1 > k2) swap(k1, k2);
    if (k1 > k3) swap(k1, k3);
    if (k2 > k3) swap(k2, k3);
    if (k1 == 1) {
        cout << "YES";
        return 0;
    }
    if (k1 == 2) {
        if (k2 == 2) {
            cout << "YES";
            return 0;
        }
        if (k2 == 4 && k3 == 4) {
            cout << "YES";
            return 0;
        }
        cout << "NO";
        return 0;
    }
    if (k1 == 3 && k2 == 3 && k3 == 3) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}