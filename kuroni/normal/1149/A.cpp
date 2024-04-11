#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;

int n, u, a[3];

bool print(int u)
{
    if (a[u] > 0)
    {
        printf("%d ", u);
        a[u]--;
        return true;
    }
    else
        return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        a[u]++;
    }
    print(2);
    print(1);
    while (print(2));
    while (print(1));
}