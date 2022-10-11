#include <iostream>
#include <cstdio>
using namespace std;

int q, mx, my, x, y;
char c;

int main()
{
    scanf("%d\n", &q);
    while (q--)
    {
        scanf("%c %d %d\n", &c, &x, &y);
        if (x > y)
            swap(x, y);
        if (c == '+')
        {
            mx = max(mx, x);
            my = max(my, y);
        }
        else
            printf("%s\n", (mx <= x && my <= y) ? "YES" : "NO");
    }
}