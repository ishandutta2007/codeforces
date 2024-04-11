#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
set <ii> S;
int res1[Maxn], res2[Maxn];

void Print()
{
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d%c", res1[i], i + 1 <= n? ' ': '\n');
    for (int i = 1; i <= n; i++)
        printf("%d%c", res2[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        S.insert(ii(a, b));
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) if (!S.count(ii(i, j))) {
            int pnt = 0;
            for (int k = 1; k <= i; k++)
                res1[k] = res2[k] = ++pnt;
            res2[j] = pnt; res1[j] = ++pnt;
            for (int k = i + 1; k <= n; k++) if (k != j) {
                res2[k] = pnt; res1[k] = ++pnt;
            }
            Print();
            return 0;
        }
    printf("NO\n");
    return 0;
}