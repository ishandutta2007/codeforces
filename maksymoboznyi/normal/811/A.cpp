#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned ll
#define big 99999999999999999
#define small -big
using namespace std;
ll a, b, k1 = -1, k2 = 0;
int main()
{
    cin >> a >> b;
    while (1)
    {
        k1 += 2;
        if ((k1+1)*(k1+1)/4 > a)
            break;
    }
    k1 -= 2;
    while (1)
    {
        k2 += 2;
        if (k2*(k2+2)/4 > b)
            break;
    }
    k2 -= 2;
    if (k1 > k2)
        cout << "Valera";
    else
        cout << "Vladik";
    return 0;
}