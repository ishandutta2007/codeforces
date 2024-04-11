#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

constexpr int N = 1001, m = 1e9l + 7;

int64_t mpow(int64_t a, int64_t b) {
    int64_t res = 1;
    for (int64_t p = a, d = 1; d <= b; d <<= 1, (p *= p) %= m)
        if (d & b)
            (res *= p) %= m;
    return res;
}

int64_t Ans[N][N], x, y, rat;

int ans(int a, int k) {
    if (a >= k)
        return (a - k + rat + m) % m;
    if (Ans[a][k] != -1)
        return Ans[a][k];
    return Ans[a][k] = (y * ans(a, k - a) + x * ans(a + 1, k)) % m;
}

int main()
{
    int k, pa, pb;
    memset(Ans, 255, sizeof Ans);
    cin >> k >> pa >> pb;
    x = pa * mpow(pa + pb, m - 2) % m;
    y = pb * mpow(pa + pb, m - 2) % m;
    rat = pa * mpow(pb, m - 2) % m;
    cout << (ans(1, k) + k) % m;
    return 0;
}