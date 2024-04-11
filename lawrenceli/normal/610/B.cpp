#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int maxn = 200100;

int n, a[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int mi = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i%n] == mi) ans = max(ans, cur), cur = 0;
        else cur++;
    }

    cout << ans + (long long)(mi) * n << '\n';
}