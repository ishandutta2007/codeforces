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

int main()
{
    cin >> n;
    if (isprime(n))
    {
        cout << 1 << endl;
        cout << n;
        return 0;
    }
    if (isprime(n - 2))
    {
        cout << 2 << endl;
        cout << 2 << ' ' << n - 2;
        return 0;
    }
    cout << 3 << endl;
    cout << 3 << ' ';
    n -= 3;
    for (int i = 2; i < n; i++)
    {
        if (isprime(i) && isprime(n - i))
        {
            cout << i << ' ' << n - i;
            return 0;
        }
    }

    return 0;
}