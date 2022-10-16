#include <bits/stdc++.h>

using namespace std;

int n, m;

long long p(int x) {
    long long ret = n / m;
    if (x < n % m) ++ret;
    if (x == 0) --ret;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ++n;
    long long ans = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) if ((i * i + j * j) % m == 0) ans += p(i) * p(j);
    cout << ans << endl;
    return 0;
}