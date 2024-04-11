#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int u, ma = 105;
    for (int i = 1; i >= -1; i--)
    {
        scanf("%d", &u);
        ma = min(ma, u + i);
    }
    printf("%d\n", ma * 3);
}