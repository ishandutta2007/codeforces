#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int maxn = 1000005;

int f[maxn];

int main() {
    // freopen("calcxor.in", "r", stdin), freopen("calcxor.out", "w", stdout);
    long long n = read<int>(), Q = 0;
    for (long long i = 1; i <= n; i++) f[i] = f[i - 1] ^ i, Q ^= (n / i % 2 ? f[i - 1] : 0) ^ f[n % i] ^ read<long long>();
    printf("%lld\n", Q);
    return 0;
}