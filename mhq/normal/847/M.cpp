#include <bits/stdc++.h>

using namespace std;
int a[20000];
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int delta = a[2] - a[1];
    bool prog = true;
    for (int i = 1; i < n; i++)
        if (a[i + 1] - a[i] != delta) prog = 0;
    if (prog) cout << a[n] + delta << "\n";
    else cout << a[n] << "\n";
    return 0;
}