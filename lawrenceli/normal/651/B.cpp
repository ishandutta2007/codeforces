#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int n, a[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }

    int x = *max_element(a, a + maxn);
    cout << n - x << '\n';
}