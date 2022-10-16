#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200005];
map <int, int> cnt;

long long f(long long x) {
    return x * (x - 1) / 2;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int all = (1 << k) - 1;
    ++cnt[0];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i-1];
        ++cnt[min(a[i], a[i] ^ all)];
    }
    long long tot = 1ll * n * (n + 1) / 2;
    for (auto x: cnt) tot -= f(x.second / 2) + f(x.second - x.second / 2);
    cout << tot << endl;
    return 0;
}