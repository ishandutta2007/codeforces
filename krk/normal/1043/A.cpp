#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        k = max(k, a[i]);
    }
    int his = 0, my = 0;
    for (int i = 0; i < n; i++) {
        his += a[i];
        my += k - a[i];
    }
    while (my <= his) {
        k++; my += n;
    }
    printf("%d\n", k);
    return 0;
}