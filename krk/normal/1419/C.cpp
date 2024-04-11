#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        bool eq = true;
        bool waseq = false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] != x) eq = false;
            else waseq = true;
            sum += a[i];
        }
        if (eq) printf("0\n");
        else if (sum % n == 0 && sum / n == x || waseq) printf("1\n");
        else printf("2\n");
    }
    return 0;
}