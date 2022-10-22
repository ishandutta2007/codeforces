#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 2000000007;

int T;
int n, x;
int a[Maxn];
int best[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        fill(best, best + n + 1, -Inf);
        best[0] = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                best[j - i + 1] = max(best[j - i + 1], sum);
            }
        }
        for (int i = n; i > 0; i--) {
            best[i - 1] = max(best[i - 1], best[i]);
            best[i] += i * x;
        }
        for (int i = 1; i <= n; i++)
            best[i] = max(best[i], best[i - 1]);
        for (int i = 0; i <= n; i++)
            printf("%d%c", best[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}