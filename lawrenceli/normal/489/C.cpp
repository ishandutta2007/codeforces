#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int m, s, a[MAXN], b[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> m >> s;
    if (s == 0) {
        if (m == 1) cout << "0 0\n";
        else cout << "-1 -1\n";
        return 0;
    }

    int n;

    n = s-1, a[m-1] = 1;
    for (int i=0; i<m && n; ) {
        if (a[i] == 9) i++;
        else a[i]++, n--;
    }
    if (n) {
        cout << "-1 -1\n";
        return 0;
    }

    n = s-1, b[m-1] = 1;
    for (int i=m-1; i>=0 && n; ) {
        if (b[i] == 9) i--;
        else b[i]++, n--;
    }

    for (int i=m-1; i>=0; i--) cout << a[i];
    cout << ' ';
    for (int i=m-1; i>=0; i--) cout << b[i];
    return 0;
}