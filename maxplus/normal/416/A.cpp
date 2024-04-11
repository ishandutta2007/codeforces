#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int l = -1000000001, r = 1000000002, n, x;
    char c1, c2, a;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("\n%c%c %d %c", &c1, &c2, &x, &a);
        if ((a == 'Y' && c2 == '=') || (a == 'N' && c2 != '='))
        {
            if ((a == 'Y' && c1 == '>') || (a == 'N' && c1 == '<'))
                l = max(x, l);
            else
                r = min(x + 1, r);
        }
        else
        {
            if ((a == 'Y' && c1 == '>') || (a == 'N' && c1 == '<'))
                l = max(x + 1, l);
            else
                r = min(x, r);
        }
        if (r <= l)
        {
            cout << "Impossible";
            return 0;
        }
    }
    cout << l;
    return 0;
}