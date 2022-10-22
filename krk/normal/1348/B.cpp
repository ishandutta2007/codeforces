#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        set <int> S;
        fill(a, a + k, 1);
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            S.insert(num);
        }
        if (S.size() > k) { printf("-1\n"); continue; }
        int pnt = 0;
        for (set <int>::iterator it = S.begin(); it != S.end(); it++)
            a[pnt++] = *it;
        printf("%d\n", n * k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                printf("%d%c", a[j], i + 1 < n || j + 1 < k? ' ': '\n');
    }
    return 0;
}