#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            res[i] = i;
        for (int i = n - 1; i > 0; i -= 2)
            swap(res[i], res[i + 1]);
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}