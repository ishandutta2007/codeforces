#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    char c1, c2;
    int i1, i2;
    cin >> c1 >> i1 >> c2 >> i2;
    cout << max(abs(c1 - c2), abs(i1 - i2)) << '\n';
    while (!(c1 == c2 && i1 == i2))
    {
        if (c1 < c2)
        {
            cout << 'R';
            c1++;
        }
        else if (c1 > c2)
        {
            cout << 'L';
            c1--;
        }

        if (i1 < i2)
        {
            cout << 'U';
            i1++;
        }
        else if (i1 > i2)
        {
            cout << 'D';
            i1--;
        }
        cout << '\n';
    }
}