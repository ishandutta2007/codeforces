#include <bits/stdc++.h>
using namespace std;
int n;
int f[5005];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        if (f[f[f[i]]] == i) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}