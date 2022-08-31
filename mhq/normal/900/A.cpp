#include <bits/stdc++.h>
using namespace std;
int a1 = 0;
int a2 = 0;
int a[(int)1e5 + 2];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > 0) a1++;
        else a2++;
    }
    if (a1 <= 1 || a2 <= 1) {
        cout << "YES";
    }
    else cout << "NO";
}