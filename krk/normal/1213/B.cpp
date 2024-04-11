#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int t;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int bad = 0, mn = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            bad += a[i] > mn;
            mn = min(mn, a[i]);
        }
        printf("%d\n", bad);
    }
    return 0;
}