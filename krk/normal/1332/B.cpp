#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxd = 11;
const int primes[Maxd] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int T;
int n;
bool usd[Maxd];
int rl[Maxd];
int col[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(usd, usd + Maxd, false);
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            int j = 0;
            while (a % primes[j]) j++;
            col[i] = j; usd[j] = true;
        }
        int id = 0;
        for (int i = 0; i < Maxd; i++)
            if (usd[i]) rl[i] = ++id;
        printf("%d\n", id);
        for (int i = 1; i <= n; i++)
            printf("%d%c", rl[col[i]], i + 1 <= n? ' ': '\n');
    }
    return 0;
}