#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[1000002], mod = 1000003;
ll fact(ll n, ll i)
{
    ll tmp1 = n, tmp2 = i;
    while (!(tmp2%2))
    {
        tmp1--;
        tmp2 /= 2;
    }
    tmp1 = tmp1 % (mod - 1);
    return (A[tmp1] - tmp2);
}
int main()
{
    ll n, k, x = 1, y, save, prev, tmp, t, cur;
    int i;
    A[0] = 1;
    for (i = 1; i < 1000002; i++) A[i] = (A[i-1] * 2) % mod;
    scanf("%I64d %I64d", &n, &k);
    prev = n;
    if (n < 60) if ((ll)pow(2,n) < k) {cout<<1<<" "<<1; return 0;}
    save = 1;
    t = (ll)log2(k);
    for (i = 1; i <= t; i++)
    {
        save *= 2;
        prev += (k - 1) / save;
    }
    for (i = 1; i < k; i++)
    {
        x *= fact(n,i);
        x = x % mod;
        if (x == 0) break;
    }
    y = A[(((n % (mod - 1))*(k % (mod - 1)) - prev % (mod - 1)) % (mod - 1) + (mod - 1)) % (mod - 1)];
    x = ((y - x) % mod + mod) % mod;
    printf("%I64d %I64d", x, y);
    return 0;
}