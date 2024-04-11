//force

#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return num * f;
}
template <typename T>
void write(T num) {
    if (num < 0) putchar('-'), num = -num;
    if (num > 9) write(num / 10);
    putchar(num % 10 ^ 48);
    return;
}

const int maxn = 5e5 + 5;
const int maxBit = 60;

long long a[maxn];
long long f[maxBit + 1][maxn];
int cnt[2][maxn];
int bit;

template <typename T>
inline T Min(T& a, const T b) { return a = min(a, b); }
template <typename T>
inline T Max(T& a, const T b) { return a = max(a, b); }
inline bool cmp(long long a, long long b) { return (a & ((1LL << bit) - 1)) < (b & ((1LL << bit) - 1)); }

int main() {
    // freopen("equal.in", "r", stdin), freopen("equal.out", "w", stdout);
    int n = read<int>();
    // long long c1 = read<long long>(), c2 = read<long long>(), c3 = read<long long>(),
    //           p1 = read<long long>(), p2 = read<long long>(), m = read<long long>();
    // a[1] = read<long long>(), a[2] = read<long long>();
    long long maxVal = 0;
    // for (int i = 3; i <= n; i++) maxVal = max(maxVal, a[i] = (a[i - 1] % p1 * c1 % m + a[i - 2] % p2 * c2 % m + c3) % m);
    for (int i = 1; i <= n; i++) Max(maxVal, a[i] = read<long long>());
    for (int i = 1; i <= n; i++) a[i] = maxVal - a[i];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (bit = 0; bit < maxBit; bit++) {
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++) cnt[0][i] = cnt[0][i - 1], cnt[1][i] = cnt[1][i - 1], cnt[a[i] >> bit & 1][i]++;
        for (int i = 0; i <= n; i++)
            Min(f[bit + 1][cnt[1][n] - cnt[1][n - i]], f[bit][i] + cnt[1][n - i] + (cnt[0][n] - cnt[0][n - i])),
                Min(f[bit + 1][n - cnt[0][n - i]], f[bit][i] + cnt[0][n - i] + (cnt[1][n] - cnt[1][n - i]));
    }
    write(f[maxBit][0]), puts("");
    return 0;
}