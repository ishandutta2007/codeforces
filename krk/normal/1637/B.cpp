#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int nils = 0;
            for (int j = i; j < n; j++) {
                nils += a[j] == 0;
                res += j - i + 1 + nils;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}