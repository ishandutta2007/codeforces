#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int q;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        bool was = false;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] + 1 == a[i + 1]) was = true;
        printf("%d\n", was? 2: 1);
    }
    return 0;
}