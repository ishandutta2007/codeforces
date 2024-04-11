#include <iostream>

using namespace std;

const int64_t mod = 1000000007;

int64_t fpow(int64_t a, int64_t d)
{
    int64_t ans = 1, cd = a;
    for (int i = 0; (1ll << i) <= d; ++i)
    {
        if ((1ll << i) & d)
            (ans *= cd) %= mod;
        (cd *= cd) %= mod;
    }
    return ans;
}

int64_t divi(int64_t a, int64_t b)
{
    return (a * fpow(b, mod - 2)) % mod;
}

int main()
{
    int64_t n = 1000000;
    cin >> n;
    n++;
    int64_t ans = 1;
    for (int i = n + 1; i <= n * 2; ++i)
        ans = (ans * i) % mod;
    for (int i = 1; i <= n; ++i)
        ans = divi(ans, i);
    cout << (ans - 1 + mod) % mod;
    return 0;
}