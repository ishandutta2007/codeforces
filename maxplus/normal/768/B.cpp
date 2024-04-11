#include <iostream>

using namespace std;

int getn(int64_t n, int64_t p)
{
    return (n >> (63 - __builtin_clzll(n) - __builtin_ctzll(p))) & 1;
}

int main()
{
    int64_t n, l, r, ans = 0;
    cin >> n >> l >> r;
    while (l <= r)
        ans += getn(n, l++);
    cout << ans;
    return 0;
}