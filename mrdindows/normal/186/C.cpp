#include <iostream>
using namespace std;

int binpow(int x, int n)
{
    int res = 1;
    while (n>0)
    {
        if (n&1)    res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

long long binpowmod(long long x, long long n, int mod)
{
    long long res = 1;
    while (n>0)
    {
        if (n&1)    res = (res * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

int main()
{
    int mod = 1000000007;
    long long n;
    cin >> n;
    if (n==0) 
    {
        cout << 1 << endl;
        return 0;
    }
    long long res = (binpowmod(2,n,mod) + 1) * binpowmod(2, n-1, mod);
    res %= mod;
    cout << res << endl;
    return 0;
}