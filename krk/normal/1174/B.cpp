#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
    bool odd = false, ev = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) ev = true;
        else odd = true;
    }
    if (odd && ev)
        sort(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    return 0;
}