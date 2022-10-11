#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;

int get_pair(int u)
{
    int a, b;
    cout << "? " << u << endl;
    cin >> a;
    cout << "? " << u + n / 2 << endl;
    cin >> b;
    if (a == b)
    {
        cout << "! " << u << endl;
        exit(0);
    }
    return a - b;
}

void BS(int l, int r, int si)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (1LL * get_pair(m) * si > 0)
            l = m + 1;
        else
            r = m - 1;
    }
}

int main()
{
    cin >> n;
    if (n / 2 % 2 == 1)
    {
        cout << "! -1" << endl;
        return 0;
    }
    int a = get_pair(1), b = get_pair(n / 4 + 1);
    if (1LL * a * b < 0)
        BS(2, n / 4, a);
    else
        BS(n / 4 + 2, n / 2, b);
}