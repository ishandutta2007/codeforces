#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << 1 << " ";
    int u = (a[a[1]] == b[1] || b[a[1]] == b[1]) ? a[1] : b[1];
    int prv = a[1] ^ b[1] ^ u;
    while (u != 1) {
        cout << u << " ";
        if (a[u] == prv) {
            prv = b[u];
            u = a[u];
        } else {
            prv = a[u];
            u = b[u];
        }
    }
}