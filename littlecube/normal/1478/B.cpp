#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool solve(int x, int d)
{
    if (d == 1)
        return true;

    if (d == 2)
    {
        if (x % 2 == 0)
            return true;
        if (x % 2 == 1 && x >= 21)
            return true;
    }

    if (d == 3)
    {
        if (x % 3 == 0)
            return true;
        if (x % 3 == 1 && x >= 13)
            return true;
        if (x % 3 == 2 && x >= 23)
            return true;
    }

    if (d == 4)
    {
        if (x % 4 == 0)
            return true;
        if (x % 4 == 1 && x >= 41)
            return true;
        if (x % 4 == 2 && x >= 14)
            return true;
        if (x % 4 == 3 && x >= 43)
            return true;
    }

    if (d == 5)
    {
        if (x % 5 == 0)
            return true;
        if (x % 5 == 1 && x >= 51)
            return true;
        if (x % 5 == 2 && x >= 52)
            return true;
        if (x % 5 == 3 && x >= 53)
            return true;
        if (x % 5 == 4 && x >= 54)
            return true;
    }

    if (d == 6)
    {
        if (x % 6 == 0)
            return true;
        if (x % 6 == 1 && x >= 61)
            return true;
        if (x % 6 == 2 && x >= 26)
            return true;
        if (x % 6 == 3 && x >= 63)
            return true;
        if (x % 6 == 4 && x >= 16)
            return true;
        if (x % 6 == 5 && x >= 65)
            return true;
    }

    if (d == 7)
    {
        if (x % 7 == 0)
            return true;
        if (x % 7 == 1 && x >= 57)
            return true;
        if (x % 7 == 2 && x >= 37)
            return true;
        if (x % 7 == 3 && x >= 17)
            return true;
        if (x % 7 == 4 && x >= 67)
            return true;
        if (x % 7 == 5 && x >= 47)
            return true;
        if (x % 7 == 6 && x >= 27)
            return true;
    }

    if (d == 8)
    {
        if (x % 8 == 0)
            return true;
        if (x % 8 == 1 && x >= 81)
            return true;
        if (x % 8 == 2 && x >= 18)
            return true;
        if (x % 8 == 3 && x >= 83)
            return true;
        if (x % 8 == 4 && x >= 28)
            return true;
        if (x % 8 == 5 && x >= 85)
            return true;
        if (x % 8 == 6 && x >= 38)
            return true;
        if (x % 8 == 7 && x >= 87)
            return true;
    }

    if (d == 9)
    {
        if (x % 9 == 0)
            return true;
        if (x % 9 == 1 && x >= 19)
            return true;
        if (x % 9 == 2 && x >= 29)
            return true;
        if (x % 9 == 3 && x >= 39)
            return true;
        if (x % 9 == 4 && x >= 49)
            return true;
        if (x % 9 == 5 && x >= 59)
            return true;
        if (x % 9 == 6 && x >= 69)
            return true;
        if (x % 9 == 7 && x >= 79)
            return true;
        if (x % 9 == 8 && x >= 89)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        while (n--)
        {
            ll x;
            cin >> x;
            if (solve(x, d))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}