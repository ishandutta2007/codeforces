#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
int a[Maxn];
int b[Maxn];
int res[Maxn];

void Shift(int hm, int n)
{
    for (int i = 0; i < n; i++) {
        int ni = (i - hm + n) % n;
        b[ni] = a[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = n - 1; i >= 0; i--) {
            int j = 0;
            while (a[j] != i + 1) j++;
            res[i] = ((i + 1) - (i - j)) % (i + 1);
            Shift(res[i], i + 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}