#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) a[i]--;
        printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}