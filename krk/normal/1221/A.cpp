#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;

int q;
int n;
int a[Maxb];

int main()
{
    scanf("%d", &q);
    while (q--) {
        fill(a, a + Maxb, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            int b = 0;
            while (x != (1 << b)) b++;
            a[b]++;
        }
        for (int i = 0; i < 11; i++)
            a[i + 1] += a[i] / 2;
        if (a[11] > 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}