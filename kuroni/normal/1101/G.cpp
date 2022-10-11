#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

const int N = 200005;

int n, ans = 0, a[N];
bitset<N> bi[30];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i] ^= a[i - 1];
        for (int j = 0; j < 30; j++)
            bi[j].set(i, a[i] >> j & 1);
    }
    if (a[n] == 0)
        return printf("-1"), 0;
    for (int i = n; i >= 1; i--)
    {
        int pos = ans;
        while (pos < 30 && !bi[pos].test(i))
            pos++;
        if (pos == 30)
            continue;
        swap(bi[pos], bi[ans]);
        for (int j = ++ans; j < 30; j++)
            if (bi[j].test(i))
                bi[j] ^= bi[ans - 1];
    }
    printf("%d\n", ans);
}