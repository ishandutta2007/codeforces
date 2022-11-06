#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll a, b, n = 0;

int main()
{
    cin >> a >> b;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            n += a / b;
            a %= b;
        }else
        {
            n += b / a;
            b %= a;
        }
    }
    cout << n;
    return 0;
}