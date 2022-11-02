#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, a[MAXN], b[MAXN], c[MAXN];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) cin >> b[i];
    for (int i=0; i<n-2; i++) cin >> c[i];
    sort(a, a+n), sort(b, b+n-1), sort(c, c+n-2);
    for (int i=0; i<n; i++) if (a[i] != b[i]) {cout << a[i] << ' '; break;}
    for (int i=0; i<n-1; i++) if (b[i] != c[i]) {cout << b[i] << ' '; break;}
}