#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;

int T;
int n;
int a;
int cnt[Maxb];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        fill(cnt, cnt + Maxb, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            for (int j = 0; j < Maxb; j++)
                if (a & 1 << j)
                    cnt[j]++;
        }
        int g = 0;
        for (int j = 0; j < Maxb; j++)
            g = gcd(g, cnt[j]);
        bool was = false;
        for (int i = 1; i <= n; i++) if (g % i == 0) {
            if (was) printf(" ");
            else was = true;
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}