#include <iostream>
#include <cstdio>
using namespace std;

const int N = 105;

int n, ans = 0, a[N * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < 2 * n; i += 2)
    {
        for (int j = i + 1; j <= 2 * n; j++)
            if (a[j] == a[i])
                for (; j > i + 1; j--)
                {
                    ans++;
                    swap(a[j], a[j - 1]);
                }
    }
    printf("%d", ans);
}