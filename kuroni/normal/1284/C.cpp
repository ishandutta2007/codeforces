#include <bits/stdc++.h>
using namespace std;

const int N = 3E5 + 5;

int n, m;
long long ans, fct[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fct[0] = 1;
    for (int i = 1; i <= n; i++) {
        fct[i] = fct[i - 1] * i % m;
    }
    for (int i = 1; i <= n; i++) {
        int pos = n - i + 1;
        (ans += 1LL * pos * pos % m * fct[i] % m * fct[n - i] % m) %= m;
    }
    cout << ans;
}