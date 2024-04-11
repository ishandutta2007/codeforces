#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
ll k;
int res[Maxn];

ll Aritm(int a, int b) { return ll(a + b) * (b - a + 1) / 2; }

void Print()
{
    int cur = 1;
    for (int i = 1; i <= n; i++)
        if (res[i] == 0) res[i] = cur++;
    for (int i = 1; i <= n; i++)
        printf("%d%c", i, i + 1 <= n? ' ': '\n');
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d %I64d", &n, &k);
    if (Aritm(1, n) > k) { printf("-1\n"); return 0; }
    if (n == 1) { printf("1\n1\n1\n"); return 0; }
    int a = (n + 2) / 2, b = (n + 3) / 2;
    if (Aritm(a, n) + Aritm(b, n) <= k) {
        printf("%I64d\n", Aritm(a, n) + Aritm(b, n));
        for (int i = 1; i <= n; i++)
            printf("%d%c", i, i + 1 <= n? ' ': '\n');
        for (int i = n; i > 0; i--)
            printf("%d%c", i, i - 1 > 0? ' ': '\n');
        return 0;
    }
    printf("%I64d\n", k);
    k -= Aritm(1, n);
    int cur = 1;
    for (int i = n; i > 0; i--) {
        ll tk = min(ll(i - cur), k);
        if (tk == k) {
            res[i - tk] = i;
            Print();
            return 0;
        }
        k -= tk;
        res[cur] = i; cur++;
    }
    return 0;
}