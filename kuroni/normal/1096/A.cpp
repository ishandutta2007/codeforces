#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t, l, r;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &l, &r);
        printf("%d %d\n", l, l * 2);
    }
}