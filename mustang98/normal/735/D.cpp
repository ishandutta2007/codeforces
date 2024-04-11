#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200008;

long long n;

bool isprime(ll a)
{
    if (a == 2 || a == 3) return true;
    for (ll i = 2; i * i <= a; i++)
    {
        if(a % i == 0) return false;
    }
    return true;
}

int solve(ll a)
{
    if (isprime(a)) return 1;
    for (ll i = 2; i <= n - 2; i++)
    {
        ll j = n - i;
        if (isprime(i) && isprime(j))
        {
            cout << j << ' '<<i<<endl;
            return 2;
        }
    }
    for (int i = 2; i < n; i++)
    {
        int n1 = n - i;
        for (ll i1 = 2; i1 <= n1 - 2; i1++)
        {
            ll j = n1 - i1;
            if (i + j + i1 != n) continue;
            if (isprime(i) && isprime(j) && isprime(i1))
            {
                cout << i << ' ' <<i1 <<' '<<j;
                return 3;
            }
        }
    }
    return 1500;
}

int main()
{
    cin >> n;
    if (isprime(n))
    {
        cout << 1;
        return 0;
    }
    if (n % 2 == 0)
    {
        cout << 2;
        return 0;
    }
    else
    {
        if (isprime(n - 2))
        {
            cout << 2;
        }
        else cout << 3;
    }


    return 0;
}