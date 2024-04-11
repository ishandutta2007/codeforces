#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn], b[Maxn];
int suma[Maxn], sumb[Maxn];

int getMe(int games)
{
    return suma[n] + (games - n) * 100 - suma[games / 4];
}

int getIlya(int games)
{
    int tk = min(games / 4, games - n);
    return sumb[n] - sumb[games / 4 - tk];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) {
            suma[i] = suma[i - 1] + a[i];
            sumb[i] = sumb[i - 1] + b[i];
        }
        int res = 0;
        while (getMe(n + res) < getIlya(n + res)) res++;
        printf("%d\n", res);
    }
    return 0;
}