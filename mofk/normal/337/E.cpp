#include <bits/stdc++.h>

using namespace std;

int N;
long long a[10];
int ans = 1e9;
int dad[10];
long long remain[10];
int cnt[10];
int primes;

int calc(void) {
    int ret = N - primes;
    for (int i = 1; i <= N; ++i) if (dad[i] == 0) ret += cnt[i];
    for (int i = 2; i <= N; ++i) if (dad[i] == 0) { ++ret; break; }
    return ret;
}

void backtrack(int pos) {
    if (pos > N) {
        ans = min(ans, calc());
        return;
    }
    for (dad[pos] = 0; dad[pos] < pos; ++dad[pos]) if (remain[dad[pos]] % a[pos] == 0) {
        remain[dad[pos]] /= a[pos];
        backtrack(pos + 1);
        remain[dad[pos]] *= a[pos];
    }
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    sort(a + 1, a + N + 1, greater <long long>());
    for (int i = 1; i <= N; ++i) {
        long long k = a[i];
        for (int j = 2; 1LL * j * j <= k; ++j) while (k % j == 0) k /= j, ++cnt[i];
        if (k > 1) ++cnt[i];
        if (cnt[i] == 1) ++primes;
    }
    for (int i = 1; i <= N; ++i) remain[i] = a[i];
    backtrack(1);
    cout << ans << endl;
}