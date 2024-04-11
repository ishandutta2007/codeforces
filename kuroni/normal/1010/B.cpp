#include <iostream>
#include <cstdio>
using namespace std;

const int N = 35;

int l = 1, r, n, a, p[N];

int main()
{
    cin >> r >> n;
    for (int i = 0; i < n; i++)
    {
        cout << r << endl;
        cin >> a;
        if (a == 0)
            return 0;
        p[i] = (a == -1);
    }
    for (int i = 0; l <= r; i++)
    {
        int m = (l + r) / 2;
        cout << m << endl;
        cin >> a;
        if (a == 0)
            return 0;
        if (p[i % n] == 0)
            a = -a;
        if (a == -1)
            r = m - 1;
        else
            l = m + 1;
    }
}