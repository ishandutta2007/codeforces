#include <iostream>
#include <cstdio>
using namespace std;

int ask(int c, int d)
{
    cout << "? " << c << " " << d << endl;
    int x; cin >> x; return x;
}

int main()
{
    int a = 0, b = 0, l = -2;
    for (int i = 29; i >= 0; i--)
    {
        if (l == -2)
            l = ask(a, b);
        if (l == 0)
        {
            l = ask(a, b ^ (1 << i));
            if (l == 1)
            {
                a += (1 << i);
                b += (1 << i);
            }
            l = -2;
        }
        else if (l == -1)
        {
            l = ask(a + (1 << i) - 1, b + (1 << i) - 1);
            if (l == 1)
            {
                if (ask(a, b ^ (1 << i)) == 1)
                {
                    a += (1 << i);
                    b += (1 << i);
                }
                l = -1;
            }
            else
            {
                b += (1 << i);
                l = -2;
            }
        }
        else
        {
            l = ask(a + (1 << i) - 1, b + (1 << i) - 1);
            if (l == -1)
            {
                if (ask(a, b ^ (1 << i)) == 1)
                {
                    a += (1 << i);
                    b += (1 << i);
                }
                l = 1;
            }
            else
            {
                a += (1 << i);
                l = -2;
            }
        }
    }
    cout << "! " << a << " " << b << endl;
}