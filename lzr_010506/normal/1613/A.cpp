#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        while (x1 < 1e6) x1 *= 10, p1--;
        while (x2 < 1e6) x2 *= 10, p2--;
        if (p1 > p2) putchar('>');
        else if (p1 < p2) putchar('<');
        else
        {
            if (x1 > x2) putchar('>');
            if (x1 < x2) putchar('<');
            if (x1 == x2) putchar('=');
        }
        puts("");
    }

    return 0;
}