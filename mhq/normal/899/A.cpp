#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2 * (int)1e5 + 10;
int a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int x1 = 0;
    int x2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) x1++;
        else x2++;
    }
    cout << min(x1, x2) + (x1 - min(x1, x2)) / 3;
    return 0;
}