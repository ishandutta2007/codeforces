#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
bool was[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(was + 1, was + n + 1, false);
        while (m--) {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            was[b] = true;
        }
        int i = 1;
        while (was[i]) i++;
        for (int j = 1; j <= n; j++) if (j != i)
            printf("%d %d\n", i, j);
    }
    return 0;
}