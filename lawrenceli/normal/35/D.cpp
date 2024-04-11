#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n, x, ar[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        ar[i] = (n-i)*c;
    }
    sort(ar, ar+n);
    int cnt = 0;
    for (int i=0; i<n; i++)
        if (ar[i] <= x)
            x -= ar[i], cnt++;
    cout << cnt << '\n';
    return 0;
}