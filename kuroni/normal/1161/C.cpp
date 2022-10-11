#include <iostream>
#include <cstdio>
using namespace std;

const int MX = 55;

int n, u, cnt[MX];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        cnt[u]++;
    }
    for (int i = 1; i < MX; i++)
        if (cnt[i] > 0)
            return printf("%s\n", cnt[i] > n / 2 ? "Bob" : "Alice"), 0;
}